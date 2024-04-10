#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 2;
const int C = 10;

int n, mp[300];
string s, t;
int weed[MAXN<<2][10][10][3];
int conv[MAXN*2][12];

void plant(int v, int b, int e){
	if (e - b == 1){
		if (mp[s[b]] < 3)
			for (int w = 0; w < 10; w++)
				weed[v][0][w][mp[s[b]]] = 1;
		return;
	}

	int mid = b+e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	for (int pos = 0; pos < 10 && pos<e-b; pos++)
		for (int ln = pos+1; ln <= 10; ln++)
			for (int w = 0; w < 3; w++){
				weed[v][pos][ln-1][w] = weed[v<<1][pos][ln-1][w];
				int cur = (pos>mid-b?pos-(mid-b):conv[mid-b-pos][ln]);
				if (cur)
					cur = ln-cur;
				if (pos >= mid-b) cur = pos-(mid-b);
				weed[v][pos][ln-1][w] += weed[v<<1^1][cur][ln-1][w];
			}
}

void water(int v, int b, int e, int pos, char val){
	if (e - b == 1){
		if (mp[s[b]] < 3)
			for (int w = 0; w < 10; w++)
				weed[v][0][w][mp[s[b]]] = 0;
		s[b] = val;
		if (mp[s[b]] < 3)
			for (int w = 0; w < 10; w++)
				weed[v][0][w][mp[s[b]]] = 1;
		return;
	}

	int mid = b + e >> 1;
	if (pos < mid)
		water(v<<1, b, mid, pos, val);
	else
		water(v<<1^1, mid, e, pos, val);
	for (int pos = 0; pos < 10 && pos < e-b; pos++)
		for (int ln = pos+1; ln <= 10; ln++)
			for (int w = 0; w < 3; w++){
				weed[v][pos][ln-1][w] = weed[v<<1][pos][ln-1][w];
				int cur = (pos>mid-b?pos-(mid-b):conv[mid-b-pos][ln]);
				if (cur)
					cur = ln-cur;
				if (pos >= mid-b) cur = pos-(mid-b);
				weed[v][pos][ln-1][w] += weed[v<<1^1][cur][ln-1][w];
			}
}

int smoke(int v, int b, int e, int l, int r, int cur = 0){
	if (l <= b && e <= r){
		int ret = 0;
		for (int i = 0, j = 0; i < t.size() && j < e-b; i++, j++, cur = (cur+1==(int)t.size()?0:cur+1))
			if (mp[t[cur]] == 3){
				int temp = 0;
				for (int w = 0; w < 3; w++)
					temp += weed[v][j][(int)t.size()-1][w];
				int tot = (e-b)/(int)t.size();
				int g = conv[e-b][t.size()];
				if (j < g) tot++;
				ret += tot-temp;
			}
			else{
				ret += weed[v][j][(int)t.size()-1][mp[t[cur]]];
			//	cout << ret << endl;
			}
		return ret;
	}
	if (r <= b || e <= l) return 0;

	int mid = b + e >> 1;
	return smoke(v<<1, b, mid, l, r, cur) + smoke(v<<1^1, mid, e, l, r, conv[(cur+(max(0, mid-max(b,l))))][(int)t.size()]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < MAXN*2; i++)
		for (int w = 1; w < 12; w++)
			conv[i][w] = i%w;
	mp['A'] = 0;
	mp['T'] = 1;
	mp['G'] = 2;
	mp['C'] = 3;
	cin >> s; n = s.size();
	plant(1, 0, n);
	int q;	cin >> q;
	while (q--){
		int tp; cin >> tp;
		if (tp == 1){
			int pos; char c; cin >> pos >> c, pos--;
			water(1, 0, n, pos, c);
		}
		else{
			int l, r; cin >> l >> r >> t, l--;
			cout << smoke(1, 0, n, l, r) << "\n";
		}
	}
	return 0;
}
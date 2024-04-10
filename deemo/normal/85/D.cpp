//This Innocence is Brilliant..

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int q, sz, sec[MAXN], x[MAXN], cc[4 * MAXN], val[MAXN];
string type[MAXN];
vector<ll>	weed[4 * MAXN];
map<int, int>	mp;

void water(int v, int b, int e, int p){
	if (e - b == 1){
		if (cc[v]){
			cc[v] = 0;
			weed[v][0] = 0;
		}
		else{
			cc[v] = 1;
			weed[v][0] += val[b];
		}
		return;
	}

	int mid = (b + e)/ 2;
	if (p < mid)
		water(v<<1, b, mid, p);
	else
		water(v<<1^1, mid, e, p);

	cc[v] = cc[v<<1] + cc[v<<1^1];
	for (int i = 0; i < 5; i++)
		weed[v][i] = weed[v<<1][i] + weed[v<<1^1][(i + 10 - (cc[v<<1] % 5)) % 5];
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> type[i];
		if (type[i] != "sum")	cin >> x[i], sec[sz++] = x[i];
	}
	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;
	for (int i = 0; i < sz; i++)	val[i] = sec[i], mp[sec[i]] = i;

	for (int i = 0; i < 4 * MAXN; i++)	weed[i].resize(5, 0);
	for (int i = 0; i < q; i++){
		if (type[i] == "sum")
			cout << weed[1][2] << "\n";
		else
			water(1, 0, sz, mp[x[i]]);
	}
	return	0;
}
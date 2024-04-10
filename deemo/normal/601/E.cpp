#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 2e4 + 10;
const int MAXQ = 4e4 + 10;
const int MAXK = 1e3 + 10;
const int P = 1e7 + 19;
const int Q = 1e9 + 7;

int n, k, q, val[MAXN], wei[MAXN];
int stt[MAXN], sz;
ll ks[MAXN][MAXK], ss[MAXN];
bool rmv[MAXN], que[MAXQ + 10];
vector<int>	weed[4 * MAXQ];

void water(int v, int b, int e, int l, int r, int ind){
	if (l <= b && e <= r){
		weed[v].push_back(ind);
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	water(v<<1, b, mid, l, r, ind);
	water(v<<1^1, mid, e, l, r, ind);
}

void GTA(int v, int b, int e){
	for (int ind:weed[v]){
		sz++;
		for (int i = 0; i <= k; i++)
			if (i < wei[ind])
				ks[sz][i] = ks[sz - 1][i];
			else
				ks[sz][i] = max(ks[sz - 1][i], ks[sz - 1][i - wei[ind]] + val[ind]);
	}
	
	if (e - b > 1){
		int mid = (b + e)>>1;
		GTA(v<<1, b, mid);
		GTA(v<<1^1, mid, e);
	}
	else if (que[b]){
		ll ret = 0;
		for (int i = 1; i <= k; i++)
			ret = (ret + ks[sz][i] * ss[i - 1]) % Q;
		cout << ret << "\n";
	}

	sz -= (int)weed[v].size();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> val[i] >> wei[i];
		stt[i] = i;
	}

	cin >> q;	q += n;
	for (int i = n; i < q; i++){
		int type;	cin >> type;
		if (type == 2){
			int v;	cin >> v;	v--;
			rmv[v] = 1;
			water(1, 0, MAXQ, stt[v], i, v);
		}
		if (type == 1){
			cin >> val[n] >> wei[n];
			stt[n++] = i;
		}
		if (type == 3)
			que[i] = 1;
	}
	for (int i = 0; i < n; i++)
		if (!rmv[i])
			water(1, 0, MAXQ, stt[i], q++, i);
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++)
		ss[i] = (ss[i - 1] * P) % Q;
	GTA(1, 0, MAXQ);//Get Them All
	return 0;
}
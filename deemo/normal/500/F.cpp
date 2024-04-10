#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<utility>

using namespace std;

const int MAXN = 4e3 + 10;
const int MAXT = 2e4 + 10;
const int MAXQ = 2e4 + 10;

int n, p, c[MAXN], val[MAXN], t[MAXN], cur, ss[40][MAXN];
int q, aa[MAXQ], bb[MAXQ];
int ans[MAXQ];
vector<int>	weed[4 * MAXT], que[MAXT];

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

void I_WANT_ALL_THE_ANSWERS(int v, int b, int e){
	cur++;
	for (int i = 0; i < MAXN; i++)
		ss[cur][i] = ss[cur - 1][i];
	for (int x:weed[v])
		for (int i = MAXN - 1; i >= c[x]; i--)
			ss[cur][i] = max(ss[cur][i], ss[cur][i - c[x]] + val[x]);

	if (e - b == 1)
		for (int x:que[b])
			ans[x] = ss[cur][bb[x]];
	else{
		int mid = (b + e)/ 2;
		I_WANT_ALL_THE_ANSWERS(v<<1, b, mid);
		I_WANT_ALL_THE_ANSWERS(v<<1^1, mid, e);
	}
	cur--;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> p;
	for (int i = 0; i < n; i++){
		cin >> c[i] >> val[i] >> t[i];
		water(1, 0, MAXT, t[i], t[i] + p, i);
	}

	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> aa[i] >> bb[i];
		que[aa[i]].push_back(i);
	}

	I_WANT_ALL_THE_ANSWERS(1, 0, MAXT);
	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return	0;	
}
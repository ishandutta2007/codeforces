#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, lim, a[MAXN], k, sec[MAXN];
ll sm;

bool cmp(int u, int v){return 1ll*k*(u+1)+a[u] < 1ll*k*(v+1)+a[v];}

bool check(int mid){
	k = mid;
	sm = 0;
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	for (int i = 0; i < mid; i++)
		sm += 1ll*k*(sec[i]+1)+a[sec[i]];
	return sm <= lim;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> lim;
	for (int i = 0; i < n; i++)	cin >> a[i];

	int lo = 0, hi = n+1;
	while (hi-lo>1){
		int mid = hi+lo>>1;
		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}
	check(lo);
	cout << lo << " " << sm << "\n";
	return 0;
}
/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

const int kMaxN = 500000;

int Link[kMaxN], Cnt[kMaxN], A[kMaxN];

int Find(int x) {
	if(Link[x]) 
		return Link[x] = Find(Link[x]);
	return x;
}
void Union(int a, int b) {
	a = Find(a); b = Find(b);
	if(a != b) Link[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Comment these lines before submitting
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);

	int n, m, k;
	cin >> n >> m >> k;

	long long ans = -m;
	for(int i = 1; i <= k; ++i) {
		cin >> A[i];
	}

	while(m--) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for(int i = 1; i <= n; ++i) {
		Cnt[Find(i)] += 1;
	}

	int maxx = 0;
	for(int i = 1; i <= k; ++i) {
		int node = Find(A[i]);
		ans += 1LL * Cnt[node] * (Cnt[node] - 1) / 2;
		maxx = max(maxx, Cnt[node]);
		Cnt[node] = 0;
	}

	int total = 0;
	for(int i = 1; i <= n; ++i)
		total += Cnt[i];

	ans += 1LL * total * (total - 1) / 2;
	ans += total * maxx;

	cout << ans << endl;



	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/
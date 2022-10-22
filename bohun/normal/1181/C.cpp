#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;



const int nax = 5005, inf = 1e9 + 1, mod = 998244353, pod = (1 << 10);

int n, m;
string s[1005];
int down[1005][1005];
int prawo[1005][1005];
int d[pod * 5];

void add(int pos, int ile) {
	pos += pod;
	d[pos] = ile;
	pos /= 2;
	while(pos) {
		d[pos] = min(d[pos * 2], d[pos * 2 + 1]);
		pos /= 2;
	}
}
ll ans = 0;

int daj(int x, int y, int node = 1, int le = 0, int pr = pod - 1) {
	if(y >= pr && le >= x) {
		return d[node];
	}
	int mid = (le + pr) / 2;
	int best = inf;
	if(x <= mid)
		best = daj(x, y, node * 2, le, mid);
	if(y > mid)
		best = min(best, daj(x, y, 2 * node + 1, mid + 1, pr));
	return best;
}

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] = '2' + s[i] + '2';
	}
	FOR(i, m + 5)
		s[n + 1].pb('2');
	
	FORd(i, m)
		FOR(row, n) {
			prawo[row][i] = 1;
			if(s[row][i] == s[row][i + 1])
				prawo[row][i] += prawo[row][i + 1];
		}
	FORd(row, n)
		FOR(col, m) {
			down[row][col] = 1;
			if(s[row][col] == s[row + 1][col])
				down[row][col] += down[row + 1][col];
		}
	for(int col = 1; col <= m; ++col) {
		for(int row = 1; row <= n; row++) {
		//	cout << row << " " << col << " " << prawo[row][col] << " " << down[row][col] << endl;
			add(row, prawo[row][col]);
		}
		
		for(int row = 1; row <= n; row++) {
			int K = down[row][col];
			if(row + 3 * K - 1 > n)
				continue;
			int A = row;
			int B = row + K;
			int C = row + 2 * K;
			if(down[B][col] != K || down[C][col] < K)
				continue;
			//cout << row << " " << col << " " << daj(A, A + K - 1) << endl;
			int mini = min({ daj(A, A + K - 1), daj(B, B + K - 1), daj(C, C + K - 1)});
			ans += mini;
		}
	}
	cout << ans;
	
	
	
			
	
	
				
	
	
    return 0;
}
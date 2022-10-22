#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;
const int nax = 1e6 + 111;

int n, w;
int r, t[nax];
ll res[nax];
deque <pair<int, int>> q;
int L[nax], R[nax], b[nax];

int main() {
	ios;
	cin >> n >> w;
	while(n--) {
		cin >> r;
		FOR(i, 1, r) {
			cin >> t[i];
			L[i] = r + 1;
			R[i] = -1;
			b[i] = w - (r - i);
		}
		
		FOR(i, 1, r) {
			while(ss(q) > 1 && q.back().fi <= t[i])
				q.pop_back();
			if(ss(q) == 1 && q.back().fi <= t[i]) {
				R[q.front().se] = i - 1;
				q.pop_front();
			}
			
			q.pb(mp(t[i], i));
			if(ss(q) == 1) {
				L[i] = i;
			}
			
			while(ss(q) > 0 && b[q.front().se] == i) {
				R[q.front().se] = i;
				q.pop_front();
				if(ss(q) > 0)
					L[q.front().se] = i + 1;
			}
		}
		
		if(ss(q) > 0) {
			int Last = L[q.front().se] - 1;
			while(ss(q) > 0) {
				L[q.front().se] = Last + 1;
				R[q.front().se] = b[q.front().se];
				Last = b[q.front().se];
				q.pop_front();
			}
		}
			
		
		FOR(i, 1, r) {
			if(t[i] < 0) {
				L[i] = max(L[i], w - r + 1);
				R[i] = min(R[i], r);
			}
			if(L[i] <= R[i]) {
				res[L[i]] += t[i];
				res[R[i] + 1] -= t[i];
			}
		}
	}
	
	FOR(i, 1, w) {
		res[i] += res[i - 1];
		cout << res[i] << " ";
	}
		
			
		
		
	
	
	return 0;
}
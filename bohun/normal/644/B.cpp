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

const int nax = 2e5 + 111;

int n, b;
int t[nax], d[nax];
ll s[nax];
queue <int> q;

int main() {	
	scanf("%d %d", &n, &b);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d", t + i, d + i);
		if(q.empty()) {
			q.push(i);
			s[i] = t[i];
		}
		else {
			while(!q.empty() && s[q.front()] + d[q.front()] <= t[i]) {
				ll e = s[q.front()] + d[q.front()];
				q.pop();
				if(!q.empty()) {
					s[q.front()] = e;
				}	
			}
			if(ss(q) <= b) {
				q.push(i);
				if(ss(q) == 1)
					s[i] = t[i];
			}
		}
	}
	while(!q.empty() && s[q.front()] + d[q.front()] <= 1LL * 1e18) {
			ll e = s[q.front()] + d[q.front()];
			q.pop();
			if(!q.empty()) {
				s[q.front()] = e;
			}	
}
	FOR(i, 1, n) {
		if(s[i] == 0) {
			printf("-1 ");
		}
		else {
			printf("%lld ", s[i] + d[i]);
		}
	}
	
	
			
	return 0;
}
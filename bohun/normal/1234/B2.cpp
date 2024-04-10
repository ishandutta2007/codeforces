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

const int mod = 1e9 + 7;
const int nax = 2e5 + 111;

int n, k;
int a;
map <int, int> m;
deque <int> q;

int main() {
	scanf("%d%d", &n, &k);
	FOR(i, 1, n) {
		scanf("%d", &a);
		if(m[a] == 0) {
			if(ss(q) == k) {
				int b = q.front();
				m[b] -= 1;
				m[a] += 1;
				q.pop_front();
				q.push_back(a);
			}
			else {
				m[a] += 1;
				q.push_back(a);
			}
		}
	}
	printf("%d\n", ss(q));
	while(!q.empty()) {
		printf("%d ", q.back()); 
		q.pop_back();
	}
	
	
	
	return 0;
}
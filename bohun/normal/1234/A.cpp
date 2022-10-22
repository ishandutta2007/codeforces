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

int q;
int n, sum, a;

int main() {
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &n);
		sum = 0;
		FOR(i, 1, n) {
			scanf("%d", &a);
			sum += a;
		}
		int ile = 1;
		while(ile * n < sum)
			ile += 1;
		printf("%d\n", ile);
	}
	
	
	return 0;
}
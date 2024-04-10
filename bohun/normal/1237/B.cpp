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
const int mod = 1e9 + 7;

int n;
int a[nax], b[nax], id[nax];

int main() {	
	scanf("%d", &n);
	FOR(i, 1, n)
		scanf("%d", a + i);
	FOR(i, 1, n) {
		scanf("%d", b + i);
		id[b[i]] = n - i + 1;
	}
	int ans = 0;
	int mini = n + 1;
	FOR(i, 1, n) {
		if(mini < id[a[i]])
			ans += 1;
		mini = min(mini, id[a[i]]);
	}
	printf("%d", ans);
		
	
	
				
	return 0;
}
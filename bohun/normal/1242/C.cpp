#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;

int k;
int a[15];
int b[15][5001];
map <int, int> gdzie;

bool dp[1 << 15];
int jak[1 << 15];
pair <int, int> bonzo[1 << 15];
pair<int, int> opt[15]; // gdzie i co brac
bool used[15];
ll sum;
ll kub[15];
ll need;

void go(int i, int j) {
	for(int g = 0; g < k; ++g)
		used[g] = 0;
	int node = i;
	int val = b[i][j];
	int maska = 0;
	while(true) {
		maska ^= (1 << node);
		used[node] = 1;
		ll ja = need - (kub[node] - val);
		if(gdzie.find(ja) == gdzie.end())
			return;
		int on = gdzie[ja];
		opt[on] = mp(ja, node);
		if(used[on] == 1) {
			if(on == i && b[i][j] == ja) {
				bonzo[maska] = mp(i, j);
				dp[maska] = 1;
			}
			return;
		}
		node = on;
		val = ja;
	}
}

void solve(int maska) {
	if(!maska)
		return;
	if(jak[maska] == maska) {
		go(bonzo[maska].fi, bonzo[maska].se);
		return;
	}
	solve((jak[maska]));
	solve((jak[maska] ^ maska));
}
	
 
int main() {
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d", a + i);
		for(int j = 0; j < a[i]; ++j) {
			scanf("%d", &b[i][j]);
			gdzie[b[i][j]] = i;
			sum += b[i][j];
			kub[i] += b[i][j];
		}
	}
	
	if(sum % k) {
		printf("No");
		return 0;
	}
	need = sum / k;
	
	for(int i = 0; i < k; ++i) 
		for(int j = 0; j < a[i]; ++j) 
			go(i, j);	
	dp[0] = 1;
	for(int maska = 1; maska < (1 << k); ++maska) {
		for(int pod = maska; 0 < pod; pod = ((pod - 1) & maska)) {
			if(dp[pod] == 1 && dp[maska ^ pod] == 1) {
				dp[maska] = 1;
				jak[maska] = pod;
			}
		}
	}
	
	if(!dp[(1 << k) - 1]) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	solve((1 << k) - 1);
	for(int i = 0; i < k; ++i) 
		printf("%d %d\n", opt[i].fi, opt[i].se + 1);
	
			
			
		
	
	
	return 0;
}
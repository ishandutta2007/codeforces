#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;
const int MAXN = 200000;

int dp[200005];

bool pri[200005];
bitset<200005> ok;

void sieve()
{
	for(int i = 2; i <= MAXN; i ++) pri[i] = true;
	for(int i = 2; i <= MAXN; i ++) {
		if(!pri[i]) continue;
		for(int j = i * 2; j <= MAXN; j += i) pri[j] = false;
	}
	
	for(int i = 1; i <= MAXN; i ++) {
		if(i != 1 && !pri[i]) continue;
		for(int j = i * 2; j <= MAXN; j += i) if(pri[j / i]) ok[j] = true;
	}
}

vector<bitset<200005> > hv;
int n, f;
int b[100005], w[100005], r[100005];

int main()
{
	scanf("%d%d", &n, &f);
	sieve();
	ok[f] = false;
	dp[0] = 0;
	hv.push_back(ok);
	for(int i = 1; i < MAXN; i ++) {
		dp[i] = -1;
		rep(j, hv.size()) if(!hv[j][i]) {
			dp[i] = j;
			break;
		}
		if(dp[i] == -1) {
			dp[i] = hv.size();
			hv.push_back(ok << i);
		} else hv[dp[i]] |= ok << i;
	}
	int ans = 0;
	rep(i, n) {
		scanf("%d%d%d", &b[i], &w[i], &r[i]);
		ans ^= dp[r[i] - w[i] - 1];
		ans ^= dp[w[i] - b[i] - 1];
	}
	if(ans) printf("Alice\nBob\n");
	else printf("Bob\nAlice\n");
	return 0;
}
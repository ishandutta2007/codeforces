#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 1e9 + 7;

int sev[100005], dp[100005];

int pw(int a, int b) {
	if(b == 0) 
		return 1;
	int t = pw(a, b/2);
	if(b & 1)
		return t * t % M * a % M;
	else
		return t * t % M;
}

int inv(int x) {
	return pw((x % M + M) % M, M - 2);
}
void dfs(vi&v,int a, int & r, int s, int i)
{
	r += s * a;
	for (;i<v.size();i++)
		dfs(v,a/v[i],r,-s,i+1);
}
int g(int a, int b) {
	vector<int> v;
	while (sev[b]) {
		int p = sev[b];
		v.push_back(p);
		while (b % p == 0)
			b /= p;
	}
	int ret = 0;
	dfs(v,a,ret,1,0);
	return ret;
}

int32_t main()
{
	IO_OP;
	
	int m;
	cin >> m;
	dp[1] = 0;
	int invm = inv(m);
	for(int i=2;i<=m;i++) {
		if(sev[i]) continue;
		sev[i] = i;
		for(int j=i*i;j<=m;j+=i)
			sev[j] = i;
	}
	for(int i=2;i<=m;i++) {
		int tmp = 0;
		for(int j=1;j*j<=i;j++) {
			if(i%j == 0) {
				tmp += dp[j] * g(m/j, i/j) % M;
				tmp %= M;
				if(j * j != i && j != 1) {
					tmp += dp[i/j] * g(m/(i/j), j) % M;
					tmp %= M;
				}
			}
		}
		dp[i] = (1 + tmp * invm) % M * inv(1-(m/i) * invm) % M;
	}
	int ans = 0;
	for(int i=1;i<=m;i++) {
		ans += dp[i] + 1;
		ans %= M;
	}
	ans *= invm;
	ans %= M;
	cout << ans << endl;
}
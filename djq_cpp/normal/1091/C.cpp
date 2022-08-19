#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

vector<LL> S;

void check(int n, int x)
{
	S.push_back(n / x + 1LL * n * (n / x - 1) / 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i * i <= n; i ++) {
		if(n % i != 0) continue;
		check(n, i);
		check(n, n / i);
	}
	sort(S.begin(), S.end());
	S.resize(unique(S.begin(), S.end()) - S.begin());
	rep(i, S.size()) printf("%lld ", S[i]);
	return 0;
}
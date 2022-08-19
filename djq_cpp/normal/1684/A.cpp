#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
void solve()
{
	scanf("%d", &n);
	vector<int> vec;
	do {
		vec.push_back(n % 10); n /= 10;
	} while(n > 0);
	if((int)vec.size() > 2) sort(vec.begin(), vec.end());
	printf("%d\n", vec[0]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}
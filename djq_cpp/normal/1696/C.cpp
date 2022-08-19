#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int m, n, k;
int a[50005], b[50005];
void calc(int arr[], int l, vector<pair<int, LL> >& ret)
{
	rep(i, l) {
		int cnt = 1, x = arr[i];
		while(x % m == 0) {
			x /= m; cnt *= m;
		}
		if(!ret.empty() && ret.back().first == x) ret.back().second += cnt;
		else ret.push_back(MP(x, cnt));
	}
}
void solve()
{
	scanf("%d%d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	scanf("%d", &k);
	rep(i, k) scanf("%d", &b[i]);
	vector<pair<int, LL> > A, B;
	calc(a, n, A);
	calc(b, k, B);
	if(A == B) printf("Yes\n");
	else printf("No\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
char ch[200005];

bool check(int x)
{
	int p0 = 0, p1 = x;
	rep(i, n) if(ch[i] < x) {
		if(ch[i] < p0) return false;
		p0 = ch[i];
	}
	rep(i, n) if(ch[i] > x) {
		if(ch[i] < p1) return false;
		p1 = ch[i];
	}

	p0 = -1; p1 = n;
	rep(i, n) if(ch[i] < x) p0 = i;
	for(int i = n - 1; i >= 0; i --) if(ch[i] > x) p1 = i;
	for(int i = p1; i <= p0; i ++) if(ch[i] == x) return false;
	
	rep(i, n) if(ch[i] < x || ch[i] == x && i > p0) printf("1");
	else printf("2");
	printf("\n");
	return true;
}

void solve()
{
	scanf("%d%s", &n, ch);
	rep(i, n) ch[i] -= '0';
	rep(i, 10) if(check(i)) return;
	printf("-\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}
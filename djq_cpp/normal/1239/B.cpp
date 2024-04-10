#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
char ch[300005];
int psum[300005];

int alt[300005];
int solve0_p(int l, int r, int& lb, int& rb)
{
	lb = rb = -1;
	for(int i = l; i <= r; i ++) if(i > 0 && ch[i - 1] == '(') {
		lb = i;
		break;
	}
	for(int i = l; i <= r; i ++) if(ch[i] == ')') rb = i;
	if(lb == -1 || rb == -1 || lb > rb) return -1;
	int ans = 0;
	for(int i = lb; i <= rb; i ++) ans += alt[i];
	return ans;
}

int solve0(int hmin, int& retx, int& rety)
{
	rep(i, n) if(psum[i] - 2 < hmin) alt[i] = -1;
	else if(psum[i] - 2 == hmin) alt[i] = 1;
	else alt[i] = 0;
	int cnt = 0;
	rep(i, n) if(psum[i] == hmin) cnt ++;
	
	int ans = 0;
	int lb = 0;
	rep(i, n) if(alt[i] == -1) {
		if(lb < i) {
			int cx, cy;
			int ca = solve0_p(lb, i - 1, cx, cy);
			if(ca > ans) {
				ans = ca;
				retx = cx;
				rety = cy + 1;
			}
		}
		lb = i + 1;
	}
	if(lb < n) {
		int cx, cy;
		int ca = solve0_p(lb, n - 1, cx, cy);
		if(ca > ans) {
			ans = ca;
			retx = cx;
			rety = cy + 1;
		}
	}
	ans += cnt;
	return ans;
}

int solve1(int hmin, int& retx, int& rety)
{
	rep(i, n) if(psum[i] < hmin) alt[i] = -1;
	else if(psum[i] == hmin) alt[i] = 1;
	else alt[i] = 0;
	int lb = -1, rb = -1;
	rep(i, n) if(alt[i] == -1) {
		lb = i;
		break;
	}
	rep(i, n) if(alt[i] == -1) rb = i;
	
	while(lb > 0 && ch[lb - 1] != ')') lb --;
	if(lb == 0) return -1;
	while(rb < n && ch[rb] != '(') rb ++;
	if(rb == n) return -1;
	
	int ans = 0;
	rep(i, n) if(i < lb || i > rb) ans += alt[i];
	else if(psum[i] + 2 == hmin) ans ++;
	retx = lb;
	rety = rb + 1;
	
	return ans;
}

int main()
{
	scanf("%d%s", &n, ch);
	
	psum[0] = 0;
	rep(i, n) psum[i + 1] = psum[i] + (ch[i] == '(' ? 1 : -1);
	if(psum[n] != 0) {
		printf("0\n1 1\n");
		return 0;
	}
	
	int cmin = 0;
	rep(i, n) cmin = min(cmin, psum[i]);
	int ans = 0, ax = 1, ay = 1;
	rep(i, n) ans += psum[i] == cmin;

	for(int i = cmin - 2; i <= cmin; i ++) {
		int cx, cy;
		int ca = solve0(i, cx, cy);
		if(ca > ans) {
			ans = ca;
			ax = cx;
			ay = cy;
		}
	}

	for(int i = cmin + 1; i <= cmin + 2; i ++) {
		int cx, cy;
		int ca = solve1(i, cx, cy);
		if(ca > ans) {
			ans = ca;
			ax = cx;
			ay = cy;
		}
	}
	
	printf("%d\n%d %d\n", ans, ax, ay);
	return 0;
}
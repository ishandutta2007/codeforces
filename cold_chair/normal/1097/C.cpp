#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int N = 5e5 + 5;

char s[N];
int n, m, a[N], a0, ans;

int main() {
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%s", s + 1);
		m = strlen(s + 1);
		int p = 0, mi = 0, mx = 0;
		fo(i, 1, m) {
			p += s[i] == '(';
			p -= s[i] == ')';
			mi = min(mi, p);
			mx = max(mx, p);
		}
		if(p > 0) {
			if(mi < 0) continue;
			a[++ a0] = p;
		} else {
			if(mi < p) continue;
			a[++ a0] = p;
		}
	}
	sort(a + 1, a + a0 + 1);
	int r = a0;
	fo(i, 1, a0) {
		while(i < r && a[i] + a[r] > 0) r --;
		if(i < r && a[i] + a[r] == 0) {
			ans ++; r --;
		}
	}
	printf("%d\n", ans);
}
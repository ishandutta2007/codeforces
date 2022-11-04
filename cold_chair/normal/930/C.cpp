#include<cstdio>
#include<cstring>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int N = 2e5 + 5;

int n, m, x, y, s[N], ans;

int pl, pr, px;

struct tree {
	int t[N * 4];
	void add(int i, int x, int y) {
		if(y < pl || x > pr) return;
		if(x >= pl && y <= pr) {
			t[i] = max(t[i], px);
			return;
		}
		int m = x + y >> 1;
		add(i + i, x, m); add(i + i + 1, m + 1, y);
		t[i] = max(t[i + i], t[i + i + 1]);
	}
	void fi(int i, int x, int y) {
		if(y < pl || x > pr) return;
		if(x >= pl && y <= pr) {
			px = max(px, t[i]);
			return;
		}
		int m = x + y >> 1;
		fi(i + i, x, m); fi(i + i + 1, m + 1, y);
	}
} a, b;

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &m);
	fo(i, 1, n) {
		scanf("%d %d", &x, &y);
		s[x] ++; s[y + 1] --;
	}
	fo(i, 1, m) {
		s[i] += s[i - 1];
		px = 0; pl = 0; pr = s[i];
		a.fi(1, 0, m);
		int px0 = px + 1;
		ans = max(ans, px0);
		px = 0; pl = s[i]; pr = m;
		a.fi(1, 0, m); b.fi(1, 0, m);
		px ++; pl = pr = s[i]; b.add(1, 0, m);
		ans = max(ans, px);
		px = px0; a.add(1, 0, m);
	}
	printf("%d", ans);
}
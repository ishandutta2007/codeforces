#include<cstdio>
#include<cstring>
#define gc getchar
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define i0 i + i
#define i1 i + i + 1
#define pr printf
using namespace std;

char read() {
	char c = gc();
	while(c < 'A' || c > 'Z') c = gc();
	return c;
}

char C;

const int N = 2e5 + 5;

int n, q, x, a[N], a2[3];
int b[3][8][8];
int t[N * 4][8][8], z[N * 4], pc;

void add(int i, int x, int y, int c, int l, int r) {
	if(x == y) {
		z[i] = a2[pc];
		fo(j, 0, 7) fo(k, 0, 7) t[i][j][k] = b[pc][j][k];
		return;	
	}
	int m = x + y >> 1;
	if(c <= m) {
		add(i0, x, m, c, l, r | z[i1]);
	} else {
		add(i1, m + 1, y, c, l | z[i0], r);
	}
	fo(j, 0, 7) fo(k, 0, 7) {
		t[i][j][k] = t[i0][j][k | z[i1]] + t[i1][j | z[i0]][k];
	}
	z[i] = z[i0] | z[i1];
}

int main() {
	a2[0] = 1; a2[1] = 2; a2[2] = 4;
	scanf("%d %d", &n, &q);
	fo(i, 0, 2) {
		fo(j, 0, 7) fo(k, 0, 7) {
			int li = (i + 2) % 3, ni = (i + 1) % 3;
			int yy = 1;
			#define p(x, y) ((x & a2[y]) > 0)
			yy &= !(p(j, ni) && !p(j, li));
			yy &= !(p(k, ni) && !p(k, li));
			b[i][j][k] = yy;
		}
	}
	fo(i, 1, n) {
		C = read();
		a[i] = C == 'R' ? 0 : (C == 'P' ? 1 : 2); 
	}
	fo(i, 1, n) {
		pc = a[i];
		add(1, 1, n, i, 0, 0);
	}
	pr("%d\n", t[1][0][0]);
	fo(ii, 1, q) {
		scanf("%d", &x); C = read();
		pc = C == 'R' ? 0 : (C == 'P' ? 1 : 2);
		add(1, 1, n, x, 0, 0);
		pr("%d\n", t[1][0][0]);
	}
}
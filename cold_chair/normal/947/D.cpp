#include<cstdio>
#include<cstring>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

const int N = 1e5 + 5;

char s[N], t[N]; int n;
int p[N][3], q[N][3], a, b, c, d;
int u[3], v[3];
int l[N], r[N];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%s", s + 1); n = strlen(s + 1);
	fo(i, 1, n) {
		fo(j, 0, 2) p[i][j] = p[i - 1][j];
		p[i][s[i] - 'A'] ++;
		if(s[i] == 'A') l[i] = l[i - 1] + 1; else l[i] = 0;
	}
	scanf("%s", t + 1); n = strlen(t + 1);
	fo(i, 1, n) {
		fo(j, 0, 2) q[i][j] = q[i - 1][j];
		q[i][t[i] - 'A'] ++;
		if(t[i] == 'A') r[i] = r[i - 1] + 1; else r[i] = 0;
	}
	scanf("%d", &n);
	for(; n; n --) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		fo(j, 0, 2) u[j] = p[b][j] - p[a - 1][j];
		fo(j, 0, 2) v[j] = q[d][j] - q[c - 1][j];
		
		int la = min(l[b], b - a + 1), ra = min(r[d], d - c + 1);
		if(la < ra) {
			printf("0"); continue;
		}
		
		if(u[1] + u[2] > v[1] + v[2]) {
			printf("0"); continue;
		}
		if((u[1] + u[2]) % 2 != (v[1] + v[2]) % 2) {
			printf("0"); continue;
		}
		if((u[1] + u[2]) == 0 && (v[1] + v[2]) > 0 && la == ra) {
			printf("0"); continue;
		}
		if(la % 3 == ra % 3) {
			printf("1"); continue;
		}
		if((u[1] + u[2]) < (v[1] + v[2])) printf("1"); else printf("0");
	}
}
#include<cstdio>
#include<cstring>
#define pr printf
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int N = 1e6 + 5;

int T, k, n;
char s[N], a[N], b[N];
int p[26], u[26], c[26];

int main() {
	scanf("%d", &T);
	fo(ii, 1, T) {
		scanf("%d", &k);
		scanf("%s\n%s\n%s", s + 1, a + 1, b + 1);
		n = strlen(s + 1);
		fo(i, 1, n) s[i] -= 'a', a[i] -= 'a', b[i] -= 'a';
		fo(j, 0, k - 1) p[j] = -1, u[j] = -1, c[j] = 0;
		int x = 1;
		for(; x <= n; x ++) {
			c[s[x]] ++;
			if(p[s[x]] == a[x]) continue;
			if(p[s[x]] == -1 && u[a[x]] == -1) {
				p[s[x]] = a[x];
				u[a[x]] = s[x];
				continue;
			}
			break;
		}
		if(x <= n) {
			c[s[x]] --;
			int xx = x;
			for(; x > 0; x --) {
				if(p[s[x]] > a[x]) break;
				if(x != xx) {
					c[s[x]] --;
					p[s[x]] = !c[s[x]] ? -1 : p[s[x]];
					u[a[x]] = !c[s[x]] ? -1 : u[a[x]];
				}
				if(p[s[x]] != -1) continue;
				int ye = -1;
				fo(j, a[x] + 1, k - 1) if(u[j] == -1) {
					ye = j; break;
				}
				if(ye == -1) continue;
				p[s[x]] = ye; u[ye] = s[x];
				break;
			}
//		pr("%d\n", x);
			if(x == 0) {
				printf("NO\n"); continue;
			}
			for(x ++; x <= n; x ++) {
				if(p[s[x]] != -1) continue;
				int ye = -1;
				fo(j, 0, k - 1) if(u[j] == -1) {
					ye = j; break;
				}
				p[s[x]] = ye; u[ye] = s[x];
			}
		}
		fo(i, 0, k - 1) if(p[i] == -1) {
			fo(j, 0, k - 1) if(u[j] == -1) {
				p[i] = j; u[j] = i; break;
			}
		}
		int ans = 1;
		fo(i, 1, n) {
			s[i] = p[s[i]];
			if(s[i] < b[i]) break;
			if(s[i] > b[i]) {
				ans = 0; break;
			}
		}
		if(!ans) {
			printf("NO\n");
		} else {
			pr("YES\n");
			fo(i, 0, k - 1) putchar('a' + p[i]);
			putchar('\n');
		}
	}
}
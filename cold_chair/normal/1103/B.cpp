#include<cstdio>
#include<cstring>
#define pp printf
#define fl fflush(stdout)
#define fo(i ,x, y) for(int i = x; i <= y; i ++)
using namespace std;

char s[1005]; int ls;

int pd(int x, int y) {
	pp("? %d %d\n", x, y);
	fl;
	scanf("%s", s);
	return s[0] == 'x';
}

int main() {
//	freopen("a.in", "r", stdin);
	while(scanf("%s", s) != EOF) {
		if(s[0] == 'e')  return 0;
		int x, y;
		for(x = 1, y = 2; !pd(x, y); x *= 2, y *= 2);
		while(x + 1 < y) {
			int m = x + y >> 1;
			if(pd(x - 1, m)) y = m; else x = m + 1;
		}
		if(x == 1 && y == 2) {
			if(pd(1, 2) && pd(2, 3)) {
				pp("! 1\n");
				fl;
				continue;
			}
		}
		if(x + 1 == y) {
			pp("! %d\n", pd(x, y) ? y : x);
			fl;
		}
		if(x == y) {
			pp("! %d\n", x);
			fl;
		}
	}
}
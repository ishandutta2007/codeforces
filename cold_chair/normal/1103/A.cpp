#include<cstdio>
#include<cstring>
#define pp printf
#define fo(i ,x, y) for(int i = x; i <= y; i ++)
using namespace std;

int n, s0, s1;
char s[1005];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	fo(i, 1, n) {
		if(s[i] == '0') {
			pp("2 %d\n", s1 + 1);
			s1 = (s1 + 1) % 4;
		} else {
			pp("1 %d\n", s0 ? 1 : 3);
			s0 = !s0;
		}
	}
}
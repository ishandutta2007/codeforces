#include<cstdio>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

int ans;
char s[3], t[3];

int main() {
	scanf("%s", s);
	fo(i, 1, 5) {
		scanf("%s", t);
		ans |= s[0] == t[0] || s[1] == t[1] || s[0] == t[1] || s[1] == t[0];
	}
	printf("%s", ans ? "YES" : "NO");
}
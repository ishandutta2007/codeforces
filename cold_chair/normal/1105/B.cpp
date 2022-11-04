#include<cstdio>
#include<cstring>
#include<algorithm>
#define pp printf
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define abs(a) ((a) > 0 ? (a) : -(a))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

const int N = 2e5 + 5;

int n, k;
char s[N];
int ans[N];

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	int la = 1;
	fo(i, 2, n + 1) {
		if(s[i] != s[i - 1] || i == n + 1) {
			ans[s[i - 1]] += la / k;
			la = 1;
		} else la ++;
	}
	int s = 0;
	fo(i, 0, 255)  s = max(s, ans[i]);
	pp("%d\n", s);
}
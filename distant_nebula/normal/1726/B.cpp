#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
const int N=2000005;
int T, n, m;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		int d=m/n;
		if((!(n&1)&&(m&1))||m<n) { puts("No"); continue; }
		puts("Yes");
		int x=(n-1)/2*2;
		n-=x;
		m-=x;
		while(x--) printf("%d ", 1);
		m/=n;
		while(n--) printf("%d ", m);
		puts("");
	}
	return 0;
}
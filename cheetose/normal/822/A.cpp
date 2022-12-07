#include<cstdio>
#include<algorithm>
using namespace std;
int fact(int n)
{
	if (n == 0)return 1;
	return n*fact(n - 1);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d", fact(min(n, m)));
}
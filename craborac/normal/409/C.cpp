#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	printf("%d", min(min(min(min(a, b), c / 2), d / 7), e / 4));
	return 0;
}
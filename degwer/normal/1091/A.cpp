#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", min(a + 1, min(b, c - 1)) * 3);
}
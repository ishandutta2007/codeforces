#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	char s[500];
	scanf("%d%s", &num, s);
	int r = 0;
	for (int i = 0; i < num; i++)r += s[i] == '8';
	printf("%d\n", min(num / 11, r));
}
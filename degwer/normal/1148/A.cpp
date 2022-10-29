#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll a, b, c;
	scanf("%I64d%I64d%I64d", &a, &b, &c);
	printf("%I64d\n", c + c + min(a, b)*2 + (a != b));
}
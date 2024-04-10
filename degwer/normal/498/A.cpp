#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll sx, sy, tx, ty;
	scanf("%I64d%I64d%I64d%I64d", &sx, &sy, &tx, &ty);
	int num, cnt = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		ll za, zb, zc;
		scanf("%I64d%I64d%I64d", &za, &zb, &zc);
		if ((za*sx + zb*sy < -zc) != (za*tx + zb*ty < -zc))cnt++;
	}
	printf("%d\n", cnt);
}
#include<cstdio>
#define INF 9000000000000000000LL
typedef long long ll;
int main() {
	ll ax, ay, bx, by, cx, cy;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &ax, &ay, &bx, &by, &cx, &cy);
	double at,bt;
	if (by - ay == 0) at = INF;
	else at= (double)(bx - ax) / (by - ay);
	if (cy - by == 0) bt = INF;
	else bt = (double)(cx - bx) / (cy - by);
	if (at == bt)
	{
		puts("No");
		return 0;
	}
	ll a = (bx - ax)*(bx - ax) + (by - ay)*(by - ay);
	ll b= (bx - cx)*(bx - cx) + (by - cy)*(by - cy);
	if (a == b)puts("Yes");
	else puts("No");
}
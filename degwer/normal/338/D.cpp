#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
#define INF 2000000000000000000LL
pii extgcd(ll a, ll b)//ax+by=gcd(a,b) (x,y)
{
	if (a == 0)
	{
		if (b > 0)return make_pair(0, 1);
		else return make_pair(0, -1);
	}
	else if (b == 0)
	{
		if (a > 0)return make_pair(1, 0);
		else return make_pair(-1, 0);
	}
	else if (abs(a) < abs(b))
	{
		ll p = b / a, q = b - p*a;
		pii z = extgcd(a, q);
		return make_pair(z.first - p*z.second, z.second);
	}
	else
	{
		ll p = a / b, q = a - p*b;
		pii z = extgcd(q, b);
		return make_pair(z.first, z.second - p*z.first);
	}
}
ll gcd(ll a, ll b)
{
	if (a == 0)return b;
	if (b == 0)return a;
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
void no()
{
	printf("NO\n");
	exit(0);
}
ll d[10000];
int main()
{
	/*for (;;)
	{
		ll a, b, c, d;
		scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);
		pii z = extgcd(a, b, c, d);
		printf("%I64d %I64d\n", z.first, z.second);
	}*/
	ll mx, my, num;
	scanf("%I64d%I64d%I64d", &mx, &my, &num);
	for (int i = 0; i < num; i++)scanf("%I64d", &d[i]);
	ll lcm = 1;
	for (int i = 0; i < num; i++)
	{
		ll g = gcd(lcm, d[i]);
		if (double(lcm)*double(d[i]) / double(g)>1e13)no();
		lcm = lcm / g*d[i];
	}
	if (lcm > mx)no();
	ll sx = 1, sy = 0;
	for (int i = 0; i < num; i++)
	{
		pii z = extgcd(sx,-d[i]);
		ll g = gcd(sx, d[i]);
		if ((-i - sy) % g != 0)no();
		sy = ((-i - sy) / g*z.first) % (d[i] / g)*sx + sy;
		sx = sx / g*d[i];
		//printf("%I64d %I64d   %I64d    %I64d %I64d\n",z.first,z.second, g, sx, sy);
		sy = (sy%sx + sx) % sx;
	}
	if (sy == 0)sy += sx;
	if (sy> my - num + 1)no();
	//printf("%I64d\n", lcm);
	for (int i = 0; i < num; i++)
	{
		//printf("%I64d %I64d\n", d[i], gcd(sy + i, lcm));
		if (gcd(sy + i, lcm) != d[i])no();
	}
	printf("YES\n");
}
#include <stdio.h>
#define MOD 1000000007

long long a[100005];

long long pow(long long x, long long p)
{
	if(p == 0)	return 1;
	if(p & 1)	return x * pow(x, p - 1) % MOD;
	long long half = pow(x, p / 2);
	return half * half % MOD;
}

long long x1, x2, y1, y2;
int gcd(int a, int b)
{
	if(!b)	return a;
	long long q = a / b;
	x1 -= x2 * q;	y1 -= y2 * q;
	long long t = x1;	x1 = x2;	x2 = t;
	t = y1;	y1 = y2;	y2 = t;
	return gcd(b, a % b);
}

int main()
{
	int N;	scanf("%d", &N);
	for(int i = 0; i < N; i++)	scanf("%lld", &a[i]);

	bool isEven = false;
	for(int i = 0; i < N; i++)	if(!(a[i] & 1))	isEven = true;

	y1 = 1; x2 = 1;
	gcd(MOD, 3);

	long long rev = x1;

	long long ANG = 2;

	for(int i = 0; i < N; i++)	ANG = pow(ANG, a[i]);

	y1 = x2 = 1;	x1 = y2 = 0;
	gcd(MOD, 2);	while(x1 < 0)	x1 += MOD;

	ANG = ANG * x1 % MOD;

	if(isEven)
	{
		printf("%lld/%lld", (ANG + 1) * rev % MOD, ANG);
	}
	else
	{
		printf("%lld/%lld", (ANG - 1 + MOD) * rev % MOD,  ANG);
	}
	return 0;
}
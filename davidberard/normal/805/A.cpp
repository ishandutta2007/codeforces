#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long int lli;

char sieve[100000];
char primes[47000];
int pcount;

void getPrimes();

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	int a, b;
	scanf("%d %d", &a, &b);
	if(a == b)
		printf("%d\n", a);
	else if(b-a == 1)
	{
		printf("%d\n", a);
	}
	else
		printf("2\n");

	return 0;
}
void getPrimes()
{
	memset(sieve, 0, sizeof(sieve));
	sieve[0] = 1;
	sieve[1] = 1;
	pcount = 0;
	for(int i=2;i<100000;++i)
	{
		if(sieve[i] == 0)
		{
			primes[pcount++] = i;
			for(lli j = (lli) i*i; j<100000;j+=i)
				sieve[(int) j] = 1;
		}
	}
}
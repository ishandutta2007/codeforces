#include <cstdio>
#include <cstring>

const int mod = 1000000007;

long long qpow( long long v, long long st )
{
	long long r = 1;
	while ( st )
	{
		if ( st&1 )
		{
			r *= v;
			if ( r >= mod ) r %= mod;
		}
		v = v * v;
		if ( v >= mod ) v %= mod;
		st = st / 2;
	}
	return r;
}

int n, k;
long long a[2048];
long long ko[2048];

int main()
{
	int i, j;
	int x;
	long long ans;
	long long kgo, kdo;
	
	scanf( "%d %d", &n, &k );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &x );
		a[i] = x;
	}
	
	ko[1] = 1;
	kgo = 1;
	kdo = 1;
	k--;
	for ( i = 2; i <= n; i++ )
	{
		kgo = kgo * (k+i-2);
		if ( kgo >= mod ) kgo = kgo % mod;
		kdo = kdo * (i-1);
		if ( kdo >= mod ) kdo = kdo % mod;
		ko[i] = ko[i-1] + kgo * qpow( kdo, mod-2 );
		if ( ko[i] >= mod ) ko[i] = ko[i] % mod;
	}
	
	int l;
	for ( i = 1; i <= n; i++ )
	{
		ans = 0;
		for ( j = 1, l = i; j <= i; j++, l-- )
		{
			ans += a[j] * ko[l];
			if ( ans >= mod ) ans = ans % mod;
		}
		if ( i < n )
			printf( "%d ", (int) ans );
		else printf( "%d\n", (int) ans );
	}
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
vector <ll> primes, gg;
bool prime(ll x)
{
	for(int i = 2; (ll) i * i <= x; ++i)
		if(x % i == 0)
			return 0;
	return 1;
}
int pt(int a, int b, int c)
{
	int res = 1;
	while(b)
	{
		if(b & 1)
			res = (ll) res * a % c;
		a = (ll) a * a % c;
		b /= 2;
	}
	return res;
}
bool daj(int x, ll mod)
{
	ll p = mod - 1;
	vector <int> divi;
	for(int i = 2; (ll) i * i <= p; ++i)
		if(p % i == 0)
		{
			divi.pb(i);
			while(p % i == 0)
				p /= i;
		}
	if(p > 1)
		divi.pb(p);
	for(auto it: divi)
		if(pt(x, (mod - 1) / it, mod) == 1)
			return 0;
	return 1;
}
int gen(ll x)
{
	for(int i = 2; 1; ++i)
		if(daj(i, x))
			return i;
}
bool ans[2000005];
void ntt(vector <int> &d, bool inv, int id)
{
	int len = ss(d);
	for(int i = 1, j = 0; len > i; ++i)
	{
		int bit = len / 2;
		while(bit & j)
			j ^= bit, bit /= 2;
		j ^= bit;
		if(i < j)
			swap(d[i], d[j]);
	}
	for(int dl = 2; len >= dl; dl *= 2)
	{
		int root = pt(gg[id], (primes[id] - 1) / dl, primes[id]);
		if(inv)
			root = pt(root, primes[id] - 2, primes[id]);
		for(int blok = 0; len > blok; blok += dl)
		{
			int go = 1;
			for(int j = 0; dl / 2 > j; ++j)
			{
				int u = d[blok + j];
				int w = (ll) go * d[blok + j + dl / 2] % primes[id];
				d[blok + j] = (u + w) % primes[id];
				d[blok + j + dl / 2] = (u - w + (w > u ? primes[id] : 0));
				go = (ll) go * root % primes[id];
			}
		}
	}
	int odw = pt(len, primes[id] - 2, primes[id]);
	if(inv)
	{
		for(int i = 0; len > i; ++i)
			d[i] = (ll) d[i] * odw % primes[id];
	}
}
				
	
int main()
{
	int n, k;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	int N = 1;
	while(N <= 1000 * k)
		N *= 2;
	vector <int> a(N), b(N);
	for(int i = 1; 100 >= i; ++i)
		if(prime((1LL << 22) * i + 1) && ss(primes) <= 3)
			primes.pb((1LL << 22) * i + 1), gg.pb(gen((1LL << 22) * i + 1));
	for(int i = 1; n >= i; ++i)
	{
		int c;
		cin >> c;
		a[c]++;
	}
	for(int i = 0; 4 > i; ++i)
	{
		b = a;
		ntt(b, 0, i);
		for(int j = 0; N > j; ++j)
			b[j] = pt(b[j], k, primes[i]);
		ntt(b, 1, i);
		for(int j = 0; N > j; ++j)
			ans[j] |= (b[j] > 0);
	}
	for(int i = 0; N > i; ++i)
		if(ans[i])
			cout << i << " ";
		
	return 0;
}
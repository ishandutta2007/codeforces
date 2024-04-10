#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e6+5;   //equals 2*sqrt(MAXN) in problem
const int M = 7;         //equals smallest x, st. product of first "x" primes > MAX
typedef long long ll;
vector<int> lp, primes, pi;
int phi[MAX+1][M+1], sz[M+1];

void factor_sieve()
{
	lp.resize(MAX);
	pi.resize(MAX);
	lp[1] = 1;
	pi[0] = pi[1] = 0;
	for (int i = 2; i < MAX; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			primes.emplace_back(i);
		}
		for (int j = 0; j < primes.size() && primes[j] <= lp[i]; j++) {
			int x = i * primes[j];
			if (x >= MAX) break;
			lp[x] = primes[j];
		}
		pi[i] = primes.size();
	}
}

void init()
{
	factor_sieve();
	for(int i = 0; i <= MAX; i++) {
		phi[i][0] = i;
	}
	sz[0] = 1;
	for(int i = 1; i <= M; i++) {
		sz[i] = primes[i-1]*sz[i-1];
		for(int j = 1; j <= MAX; j++) {
			phi[j][i] = phi[j][i-1] - phi[j/primes[i-1]][i-1];
		}
	}
}

int sqrt2(long long x)
{
	long long r = sqrt(x - 0.1);
	while (r*r <= x) ++r;
	return r - 1;
}

int cbrt3(long long x)
{

	long long r = cbrt(x - 0.1);
	while(r*r*r <= x) ++r;
	return r - 1;
}

long long getphi(long long x, int s)
{
	if(s == 0)  return x;
	if(s <= M)
  {
		return phi[x%sz[s]][s] + (x/sz[s])*phi[sz[s]][s];
	}
	if(x <= primes[s-1]*primes[s-1])
  {
		return pi[x] - s + 1;
	}
	if(x <= primes[s-1]*primes[s-1]*primes[s-1] && x < MAX)
  {
		int sx = pi[sqrt2(x)];
		long long ans = pi[x] - (sx+s-2)*(sx-s+1)/2;
		for(int i = s+1; i <= sx; ++i) {
			ans += pi[x/primes[i-1]];
		}
		return ans;
	}
	return getphi(x, s-1) - getphi(x/primes[s-1], s-1);
}

long long getpi(long long x)
{
	if(x < MAX)   return pi[x];
	int cx = cbrt3(x), sx = sqrt2(x);
	long long ans = getphi(x, pi[cx]) + pi[cx] - 1;
	for(int i = pi[cx]+1, ed = pi[sx]; i <= ed; i++)
  {
		ans -= getpi(x/primes[i-1-1]) - i + 1;
	}
	return ans;
}

long long lehmer_pi(long long x)
{
	if(x < MAX)   return pi[x];
	int a = (int)lehmer_pi(sqrt2(sqrt2(x)));
	int b = (int)lehmer_pi(sqrt2(x));
	int c = (int)lehmer_pi(cbrt3(x));
	long long sum = getphi(x, a) + (long long)(b + a - 2) * (b - a + 1) / 2;
	for (int i = a + 1; i <= b; i++)
  {
		long long w = x / primes[i-1];
		sum -= lehmer_pi(w);
		if (i > c) continue;
		long long lim = lehmer_pi(sqrt2(w));
		for (int j = i; j <= lim; j++)
    {
			sum -= lehmer_pi(w / primes[j-1]) - (j - 1);
		}
	}
	return sum;
}

long long power(long long a, long long b)
{
	long long x = 1, y = a;
	while(b)
  {
		if (b&1)  x = x * y;
		y = y * y;
		b >>= 1;
	}
	return x;
}
void solve(long long n)
{
  ll ans = 0;
  // case 1: p^3 <= n ,p is a prime
  for(int i = 0; i < (int)primes.size(); i++) {
    if (power(primes[i], 3) <= n) {
      //std::cout << primes[i] << '\n';
      ans += 1;
    }
    else {
      break;
    }
  }
  //  std::cout << "ans=" <<ans << '\n'<<'\n';
  // case 2: p*q <= n (p < q)
  // p, q is distinct primes
  ll cnt = 0;
  ll q = 0;
  for(int i = 0; i < (int)primes.size(); i++) //p
  {
    ll x = (ll)primes[i]; // p
    q = n / x; //q
    if(q <= x)continue;
    if(q == 0)continue;
    //std::cout << "p=" << x << '\n';
    //std::cout << "q=" << q << '\n';
    cnt = lehmer_pi(q);
    if (q >= primes[i]) {
      cnt -= lehmer_pi(x);
    }
    if (cnt <= 0) break;
    //std::cout << "cnt=" <<cnt << '\n';
    ans += cnt;
  }
  //  std::cout << "p*q finish!" << '\n';

  std::cout << ans << '\n';
}
int main(int argc, char const *argv[])
{
  ll n;
  init();
  scanf("%lld", &n);
  solve(n);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int NMAX = 4e4;

int sieve[NMAX];
vector<int> primes;
void setup()
{
	for(int i=2;i<NMAX;++i)
	{
		primes.push_back(i);
		if(!sieve[i])
		{
			for(int j=i*i;j<NMAX;j+=i)
			{
				sieve[j] = 1;
			}
		}
	}
}

vector<int> getFactors(int n)
{
	vector<int> ans;
	for(auto& p : primes)
	{
		if(p > n) break;
		while(n%p == 0){
			n/=p;
			ans.push_back(p);
		}
	}
	if(n != 1) {
		ans.push_back(n);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	setup();
	ll 	n, m, k;
	cin >> n >> m >> k;
	ll lo = 1, hi = m;
	if((n*m*2/k)*k == n*m*2)
	{
		cout << "YES" << endl;
		ll x = 2*n/__gcd(n*2, k);
		ll xtra = 1;
		if(x > n)
		{
			xtra = 2;
			x/=2;
		}
		k = k/__gcd(n*2/xtra, k);
		ll y = m*xtra/__gcd(k, m*xtra);

		cout << 0 << " " << 0 << endl;
		cout << x << " " << 0 << endl;
		cout << 0 << " " << y << endl;

	} else {
		cout << "NO" << endl;
	}


	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e6+100;
const ll mod = ll(1e9)+7;

ll fexp (ll a, int e)
{
	ll ret = 1LL;
	while (e>0)
	{
		if (e%2==1) ret = ret * a % mod;
		a = a*a % mod;
		e/=2;
	}
	return ret;
}

int main ()
{
	int t;
	scanf ("%d", &t);
	for (int test = 0; test < t; test++)
	{
		int n;
		ll p;
		scanf ("%d %lld", &n, &p);
		vector <int> K(n);
		for (int &x: K) scanf ("%d", &x);
		sort(K.begin(), K.end());
		
		vector <int> Exp = K;
		
		ll currSum = 0;
		ll result = 0;
		bool infty = false;
		
		int prevExp = 1e6+10;
		while (!Exp.empty())
		{
			/* Update the currSum and result (multiply by a power of k) */
			int k = Exp.back();
			Exp.pop_back();
			int delta = prevExp - k;
			prevExp = k;
			
			result = result * fexp(p, delta) % mod;
			
			/* Multiplying by p 20 times will either 
			not change the currSum at all or make it bigger than n */
			for (int i=0; i<min(delta, 20); i++)
			{
				currSum *= p;
				if (currSum > INF) infty = true;
			}
			
			/* Process all the elements equal p^k */
			while (!K.empty() && K.back()==k)
			{
				K.pop_back();
				if (infty || currSum > 0)
				{
					currSum--;
					result+=mod - 1;
				}
				else
				{
					currSum++;
					result++;
				}
				result%=mod;
			}
		}
		
		result = result * fexp(p, prevExp) % mod;
		
		printf ("%lld\n", result % mod);
	}
}
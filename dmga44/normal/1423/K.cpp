#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef LOCAL 
#include "/media/brayand/BrayanD/debugger.h"
#else
#define db(...) false
#define dbl(...) false
#define dbg(...) false
#endif

const int MAXN = 1e6 + 100;

int dp[MAXN];

bool criba[MAXN];

int T[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> primes;

    T[1] = 1;

    for(int i = 2 ; i < MAXN ; i++)
    {
    	if(criba[i] == false)
    	{
    		for(int j = i*2 ; j < MAXN ; j+=i)
    		{
    			criba[j] = true;
     		}
     		primes.push_back(i);
    	}
    	if(criba[i] == false)T[i]++;
    	T[i] += T[i-1];
    }

    reverse(primes.begin(), primes.end());

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    // for(int i = 1 ; i <= 20 ; i++)
    // {
    // 	dbl(i,T[i]);
    // }

    int cont = 0;

    for(int i = 4 ; i < MAXN ; i++)
    {
    	if(primes.size() && primes.back()*primes.back() <= i)
    	{
    		primes.pop_back();
    		cont++;
    	}
    	dp[i] = T[i]-cont;
    }

    int T;
    cin >> T;

    while(T--)
    {
    	int N;
    	cin >> N;

    	cout << dp[N] << '\n';
    }

    return 0;
}
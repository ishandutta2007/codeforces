#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;

vector<int> primes;
char sieve[100000];

void getPrimes(int N)
{
	memset(sieve, 0, N*sizeof(sieve[0]));
	for(lli i=2;i<N;++i)
	{
		if(sieve[(int) i] == 0)
		{
			for(lli j=i*i;j<N;j+=i)
				sieve[(int) j] = 1;
			primes.push_back(i);
		}
	}
}

struct comparator{
	bool operator() (const pii& a, const pii& b)
	{
		if(a.first > b.first)
			return true;
		else if(a.first == b.first)
			return a.second > b.second;
		return false;
	}
};

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	getPrimes(100000);
	vector<int> goodNumbers;
	goodNumbers.resize(N);
	for(int i=0;i<N;++i)
		cin >> goodNumbers[i];
	int dp[N];
	for(int i=0;i<N;++i)
		dp[i] = -1;
	dp[N-1] = 1; // longest sequence containing goodNumbers[i]
	int maxx = 1;
	map<int, int> Map;
	// prime index -> index of thing with largest length that's divisible by that.
	int remain = goodNumbers[N-1];
	for(int i=0;i<primes.size() && primes[i]*primes[i] <= remain;++i)
	{
		if(remain%primes[i] == 0)
		{
			Map[primes[i]] = N-1;
			while(remain%primes[i] == 0)
				remain/=primes[i];
		}
	}
	if(remain != 1)
		Map[remain] = N-1;
/*
	map<int, int>::iterator mit;
	for(mit=Map.begin();mit!=Map.end();++mit)
		cerr << mit->first << " " << mit->second << endl;
	cerr << endl;
*/
	for(int i=N-2;i>=0;--i)
	{
		dp[i] = 1;
		//cerr << " " << i << ":" << endl;
		remain = goodNumbers[i];
		for(int j=0;j<primes.size() && primes[j]*primes[j]<=remain;++j)
		{
			if(remain%primes[j] == 0)
			{
				//cerr << primes[j] << endl;
				if(Map.count(primes[j]) != 0 && dp[Map[primes[j]]] >= dp[i])
					dp[i] = dp[Map[primes[j]]]+1;
				while(remain%primes[j] == 0)
					remain /= primes[j];
			}
		}
		if(remain != 1)
		{
			if(Map.count(remain) != 0 && dp[Map[remain]] >= dp[i])
				dp[i] = dp[Map[remain]]+1;
		}
		remain = goodNumbers[i];
		for(int j=0;j<primes.size() && primes[j]*primes[j]<=remain;++j)
		{
			if(remain%primes[j] == 0)
			{
				if((Map.count(primes[j]) != 0 && dp[i] > dp[Map[primes[j]]]) || Map.count(primes[j]) == 0)
					Map[primes[j]] = i;
				while(remain%primes[j] == 0)
					remain /= primes[j];
			}
		}
		if(remain != 1 && (Map.count(remain) == 1 && dp[Map[remain]] < dp[i]) || Map.count(remain) == 0)
			Map[remain]=i;
	
		if(dp[i] > maxx)
			maxx = dp[i];
	}
/*
	for(int i=0;i<N;++i)
		cerr << dp[i] << " ";
	cerr << endl;
*/

	cout << maxx << endl;
	

	return 0;
}
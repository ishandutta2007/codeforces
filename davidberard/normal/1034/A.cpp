#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 3880;

int sieve[NMAX];
vector<int> primes;

void setup()
{
	for(int i=2;i<NMAX;++i)
	{
		if(sieve[i] == 0) {
			primes.push_back(i);
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
		int cur = 1;
		if(n%p == 0) {
			while(n%p == 0) {
				n /= p;
				cur *= p;
				ans.push_back(cur);
			}
		}
	}
	if(n > 1) ans.push_back(n);
	return ans;
}

unordered_map<int, int> mp;
void add_to(int val)
{
	if(mp.count(val) == 0) 
	{
		mp[val] = 0;
	}
	mp[val]++;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	setup();
	int N;
	cin >> N;
	vector<int> a(N);
	int fv = -1;
	bool diff = 0;
	for(auto& x : a) {
		cin >> x;
		if(fv == -1) {
			fv = x;
		} else if(fv != x) {
			diff = 1;
		}
	}
	if(!diff)
	{
		cout << -1 << endl;
		return 0;
	}
	for(auto& x : a)
	{
		auto vv = getFactors(x);
		for(auto& y : vv) {
			add_to(y);
		}
	}
	int best = -1;
	int bestval = -1;
	for(auto& x : mp)
	{
		if(x.second > bestval && x.second != N)
		{
			best = x.first;
			bestval = x.second;
		}
	}
	cout << N-bestval << endl;
	
	return 0;
}
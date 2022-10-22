#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 100005, mod = 1e9 + 7;
const int inf = 1e9, z = 0;

ll ans = 0;
int n, k;
int t[nax];
int last[nax];
bool byl[nax];
int ile = 0, nie;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; k >= i; ++i)
	{
		cin >> t[i];
		last[t[i]] = i;
		byl[t[i]] = 1;
	}
	for(int i = 1; n >= i; ++i)
	{
		if(byl[i] == 0)
		{
			nie++;
			if(i == 1 || i == n)
				ans += 2;
			else
				ans += 3;
		}
	}
	for(int i = 1; n >= i; ++i)
		byl[i] = 0;
	for(int i = 1; k >= i; ++i)
	{
		if(byl[t[i]])
			continue;
		if(t[i] > 1)
			if(last[t[i] - 1] < i)
				ans++;
		if(t[i] < n)
			if(last[t[i] + 1] < i)
				ans++;
		byl[t[i]] = 1;
	}
	cout << ans;
	
	
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define fo(i, n) for(int i = 0; n > i; ++i)
using namespace std;

const int nax = 200005, mod = 1e9 + 7;
const int inf = 1e9;

int n;
int a, t[nax];
int pref[nax];
int ans = 0;
int p, k;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> a, t[a]++;
	
	for(int i = 1; n >= i; ++i)
	{
		pref[i] = pref[i - 1] + t[i];
	}
	int id, sum = 0;
	for(int i = 1; 200000 >= i; ++i)
	{
		if(sum == 0)
			id = i;
		if(t[i] >= 1 && ans < sum + t[i] + (t[id - 1] == 1 ? 1 : 0))
		{
			p = id;
			k = i;
			ans =  sum + t[i] + (t[id - 1] == 1 ? 1 : 0);
		}
		if(t[i] >= 2)
		{
			sum += t[i];
		}
		else
		{
			sum = 0;
		}
	}
	cout << ans << endl;
	vector <int> lewo, prawo;
	if(t[p - 1] == 1)
	{
		lewo.pb(p - 1);
	}
	for(int i = p; k >= i; ++i)
	{
		lewo.pb(i);
		if(t[i] > 1)
		prawo.pb(i);
		for(int j = 2; t[i] > j; ++j)
			lewo.pb(i);
	}
	for(auto it: lewo)
		cout << it << " ";
	for(int j = ss(prawo) - 1; j >= 0; --j)
		cout << prawo[j] << " ";
			
	
	
	
	
	return 0;
}
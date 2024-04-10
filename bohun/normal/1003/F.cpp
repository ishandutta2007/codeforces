#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n;
char s[305][100005];
int p = 41;
int pp = 31;
int ppp = 37;
int hasz[305];
int mod = 1e9 + 7;
int pref[305];
int t[100005][2];
int sum = 0;
int d[100005], e[100005];
pair < int, int > ha(int lewo, int prawo)
{
	int len = prawo - lewo + 1;
	return {(pref[prawo] - ((ll)pref[lewo - 1] * t[len][0]) % mod + mod) % mod, (e[lewo] - ((ll)e[prawo + 1] * t[len][1]) % mod + mod) % mod};
}
int daj(int l, int r)
{
	int len = r - l + 1;
	pair < int, int> hh = ha(l, r);
	int i = 1;
	int ile = 0;
	while(i <= n and i + len - 1 <= n)
	{
		int j = i + len - 1;
		if(ha(i, j) == hh)
			{
				ile++;
				i = j + 1;
				continue;
			}
		i++;
	}
	if(ile == 1)
		return 1000000000;
	int nad = d[r] - d[l - 1];
	//cout << l << " " << r << " " << ile << " " << sum - nad * ile + ile * len + n - 1 - (len - 1) * ile << endl;
	return sum - nad * ile + ile * len + n - 1 - (len - 1) * ile;
}
		
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	t[0][0] = t[0][1] = 1;
	for(int i = 1; 100000 >= i; ++i)
		t[i][0] = (ll) t[i - 1][0] * pp % mod, t[i][1] = (ll) t[i - 1][1] * ppp % mod;
	scanf("%d", &n);
	for(int i = 1; n >= i; ++i)
		scanf("%s", s[i] + 1);
	
	for(int i = 1; n >= i; ++i)
	{
		int ans = 0;
		int x = strlen(s[i] + 1);
		sum += x;
		d[i] = d[i - 1] + x;
		for(int j = 1; x >= j; ++j)
			ans = ((ll) ans * p + s[i][j] - 'a' + 1) % mod;
		hasz[i] = ans;
	}
	for(int i = 1; n >= i; ++i)
	{
		pref[i] = ((ll)pref[i - 1] * pp + hasz[i]) % mod;
	}
	for(int i = n; i >= 1; --i)
		e[i] = ((ll) e[i + 1] * ppp + hasz[i]) % mod;
	int naj = sum + n - 1;
	for(int i = 1; n >= i; ++i)
		for(int j = i; n >= j; ++j)
			naj = min(naj, daj(i,j));
	cout << naj;
	
	
	

}
#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define For(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 10005, mod = 998244353;
const ll inf = 1e18;
int t, n;
string s;		

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		int poz = n + 1;
		for(int i = 0; n > i; ++i)
			if(s[i] == '8')
			{
				poz = i;
				break;
			}
		if(n - poz >= 11)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
		
	
	
		
		
		
	
    return 0;
}
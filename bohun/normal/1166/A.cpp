#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int inf = 1e9, nax = 500005;

int n, t[nax];
int a, b, c;
string s;



int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	while(n--)
	{
		cin >> s;
		t[s[0] - 'a']++;
	}
	int ans = 0;
	for(int i = 0; 26 > i; ++i)
	{
		int ja = t[i] / 2;
		int on = t[i] - ja;
		ans += ja * (ja - 1) / 2 + on * (on - 1) / 2;
	}
	cout << ans;
	
	
	
	
	
	
		
		
		
	
    return 0;
}
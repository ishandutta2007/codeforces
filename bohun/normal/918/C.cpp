#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define up(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 105;
const ll inf = 1e18;

string s;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> s;
	int n = s.size();
	int ans = 0;
	for(int i = 0; n > i; ++i)
	{
		int bil = 0;
		int q = 0;
		for(int j = i; n > j; ++j)
		{
			if(s[j] == '(')
				++bil;
			if(s[j] == ')')
				--bil;
			if(s[j] == '?')
				++q;
			while(q > bil && q > 0)
			{
				++bil;
				--q;
			}
			if(bil < 0)
				break;
			if((j - i) % 2 == 1 && bil <= q)
				ans++;
		}
	}
	cout << ans;
					
					
						
							
						
		
		
    return 0;
}
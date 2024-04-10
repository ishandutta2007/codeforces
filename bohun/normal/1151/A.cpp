#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 100005;
int n, t[nax];


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	char s[55];
	for(int i = 0; n > i; ++i)
		cin >> s[i];
	char c[4] = {'A', 'C', 'T', 'G'};
	int ans = 1e9;
	for(int i = 0; n - 4 >= i; ++i)
	{
		int cena = 0;
		for(int j = 0; 4 > j; ++j)
		{
			int mini = abs(s[i + j] - c[j]);
			if(s[i + j] > c[j])
				mini = min(mini, (int)('Z' - s[i + j]) + (int)(c[j] - 'A') + 1);
			else
				mini = min(mini, (int)('Z' - c[j]) + (int)(s[i + j] - 'A') + 1);
			cena += mini;
		}
		ans = min(ans, cena);
	}
	cout << ans;
	
			
	return 0;
}
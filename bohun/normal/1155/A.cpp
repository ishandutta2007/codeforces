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
const int nax = 100005;
int n;

	
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string s;
	cin >> n;
	cin >> s;
	for(int i = 0; n - 1 > i; ++i)
	{
		if(s[i] > s[i + 1])
		{
			cout << "YES\n";
			cout << i + 1 << " " << i + 2 << endl;
			return 0;
		}
	}
	cout << "NO";
	
	
				
			
	return 0;
}
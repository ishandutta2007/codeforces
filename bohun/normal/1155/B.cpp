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
bool jest[100005];
	
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string s;
	cin >> n;
	cin >> s;
	int wsk = 0;
	int j = 0;
	int ile = (n - 11) / 2;
	for(int i = 0; ile > i; ++i)
	{
		while(j < n && s[j] == '8')
			++j;
		if(j < n)
		{
			jest[j] = 1;
			++j;
		}
		while(wsk < n && s[wsk] != '8')
			++wsk;
		if(wsk < n)
		{
			jest[wsk] = 1;
			++wsk;
		}
	}
	j = 0;
	while(jest[j] == 1)
		++j;
	if(s[j] == '8')
		cout << "YES";
	else
		cout << "NO";
	
	
	
				
			
	return 0;
}
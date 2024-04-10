#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 26, mod = 1e9 + 7;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int n;
	n = s.size();
	int ile = 0;
	for(int i = 0; n > i; ++i)
		ile += s[i] == 'a';
	if(n % 2 == 0)
	{
		if(ile > n / 2)
			cout << n;
		else
			cout << ile * 2 - 1;
	}
	else
	{
		if(ile > n / 2)
			cout << n;
		else
			cout << ile + ile - 1;
	}
			
	return 0;
}
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
int n, m;
int t[nax];
int a, b;
int logg = 19;
vector <int> e;
int daj(int x)
{
	bool byl = 0;
	for(int i = logg; i >= 0; --i)
	{
		if(!((1 << i) & x) && byl)
			return i;
		if((1 << i) & x)
			byl = 1;
	}
	return 20;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int ile = 0;
	int x = n;
	while(daj(x) != 20)
	{
		++ile;
		e.pb(daj(x) + 1);
		x = (x ^ ((1 << (daj(x) + 1)) - 1));
		if(daj(x) == 20)
			break;
		x++;
		++ile;
	}
	cout << ile << endl;
	for(auto it: e)
		cout << it << " ";
	
	
		
	return 0;
}
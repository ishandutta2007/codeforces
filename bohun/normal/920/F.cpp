#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
const int nax = 1100005;
ll t[nax];
int n,m;
int tab[nax];
int a, b, c;
set <int> s;
int sito[nax];
int naxi = 1e6+100;
int j = (1 << 19);
void add(int ile ,int gdzie)
{
	gdzie += j;
	t[gdzie] = ile;
	gdzie /= 2;
	while(gdzie)
	{
		t[gdzie] = t[gdzie * 2] + t[gdzie * 2 + 1];
		gdzie /= 2;
	}
}
ll sum(int u, int l, int p, int x, int y)
{
	if(y >= p and l >= x)
		return t[u];
	int mid = (l + p) / 2;
	ll res = 0;
	if(mid >= x)
		res = sum(2 * u, l, mid, x ,y);
	if(mid < y)
		res += sum(2 * u + 1, mid + 1, p, x, y);
	return res;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; n >= i; ++i)
	{
		cin >> tab[i];
		add(tab[i], i);
		if(tab[i] >= 3)
			s.insert(i);
	}
	for(int i = 1; naxi >= i; ++i)
	{
		for(int j = i; naxi >= j; j += i)
			sito[j]++;
	}
	for(int i = 1; m >= i; ++i)
	{
		cin >> a >> b >> c;
		if(a == 1)
		{
			vector < int > v;
			while(a)
			{
				set < int > :: iterator it = s.lower_bound(b);
				if(it == s.end() or *it > c)
					break;
				v.push_back(*it);
				s.erase(it);
			}
			for(auto it: v)
			{
				tab[it] = sito[tab[it]];
				add(tab[it],it);
				if(tab[it] >= 3)
					s.insert(it);
			}
		}
		else
			cout << sum(1, j, 2 * j - 1, j + b, j + c) << endl;
			
			
		//for(int e = 1; n >= e; ++e)
		//	cout << e << " " << sum(1, j, 2 * j - 1, j + e, j + e) << endl;
		//cout << endl << endl;
	}
	
		

	
}
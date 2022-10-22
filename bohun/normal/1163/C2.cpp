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
const int nax = 500005, pod = (1 << 17);
int n;
int x[nax], y[nax];
int xx[nax], yy[nax];
ll ile = 0;

map < pair<int, int>, int > mapa;
map <pair<int, int>, int> WW, Bad;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; n > i; ++i)
	{
		cin >> x[i] >> y[i];
		x[i] += 100000;
		y[i] += 100000;
		xx[x[i]]++;
		yy[y[i]]++;
		if(xx[x[i]] == 2)
			++ile;
		if(yy[y[i]] == 2)
			++ile;
	}
	for(int i = 0; n > i; ++i)
	{
		mapa.clear();
		Bad.clear();
		for(int j = i + 1; n > j; ++j)
		{
			if(x[i] == x[j] || y[i] == y[j])
				continue;
			int rx = x[i] - x[j];
			int ry = y[i] - y[j];
			int G = __gcd(rx, ry);
			rx /= G;
			ry /= G;
			mapa[mp(rx, ry)]++;
		}
		for(int j = i - 1; j >= 0; --j)
		{
			if(x[i] == x[j] || y[i] == y[j])
				continue;
			int rx = x[i] - x[j];
			int ry = y[i] - y[j];
			int G = __gcd(rx, ry);
			rx /= G;
			ry /= G;
			Bad[mp(rx, ry)] = 1;
		}
		for(auto it: mapa)
		{	
			if(Bad.find(it.fi) == Bad.end())
			{
				ile++;
				WW[it.fi]++;
			}
		}
			
	}
	ile = ile * (ile - 1) / 2;
	ll k = 0;
	for(int i = 0; nax > i; ++i)
		k += (xx[i] >= 2);
	ile -= k * (k - 1) / 2;
	k = 0;
	for(int i = 0; nax > i; ++i)
		k += (yy[i] >= 2);
	ile -= k * (k - 1) / 2;
	for(auto it: WW)
		ile -= (ll) it.se * (it.se - 1) / 2;
	cout << ile;
	
	
	
	
	
		
		
	
				
    return 0;
}
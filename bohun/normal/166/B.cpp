#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n;
struct punkt{
	ll x, y;
	punkt () {}
	punkt(ll xx, ll yy)
	{
		x = xx;
		y = yy;
	}
};
ll iloczyn(punkt a, punkt b)
{
	return a.x * b.y - a.y * b.x;
}
punkt daj(punkt a, punkt b)
{
	return punkt(b.x - a.x, b.y - a.y);
}
vector <punkt> t(100005);
bool ok = 1;
bool jest(int x, int y)
{
	punkt nasz = punkt(x, y);
	int lewo = 2;
	int prawo = n;
	while(prawo > lewo + 1)
	{
		int mid = (lewo + prawo) / 2;
		punkt c = daj(t[1], t[mid]);
		punkt d = daj(t[1], nasz);
		if(iloczyn(c, d) < 0)
			lewo = mid;
		else
			prawo = mid;
	}
	int mid = lewo;
	int aa = 0, bb = 0;
	if(iloczyn(daj(t[1], t[mid]), daj(t[1], nasz)) > 0)
		aa++;
	if(iloczyn(daj(t[1], t[mid]), daj(t[1], nasz)) < 0)
		bb++;
	if(iloczyn(daj(t[mid], t[mid + 1]), daj(t[mid], nasz)) > 0)
		aa++;
	if(iloczyn(daj(t[mid], t[mid + 1]), daj(t[mid], nasz)) < 0)
		bb++;
	if(iloczyn(daj(t[mid + 1], t[1]), daj(t[mid + 1], nasz)) > 0)
		aa++;
	if(iloczyn(daj(t[mid + 1], t[1]), daj(t[mid + 1], nasz)) < 0)
		bb++;
	if(2 == mid and iloczyn(daj(t[1], t[mid]), daj(t[1], nasz)) == 0)
		return 0;
	if(iloczyn(daj(t[mid], t[mid + 1]), daj(t[mid], nasz)) == 0)
		return 0;
	if(mid + 1 == n and iloczyn(daj(t[mid + 1], t[1]), daj(t[mid + 1], nasz)) == 0)
		return 0;
		
	return (aa == 0 or bb == 0);
}	
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> t[i].x >> t[i].y;
	int q;
	cin >> q;
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		ok &= jest(x,y);
	}
	cout << (ok ? "YES" : "NO");
			
	return 0;
}
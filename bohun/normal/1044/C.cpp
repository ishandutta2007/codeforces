#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
struct punkt {
	int x, y;
};
int n;
punkt t[300005];
int minx, miny, maxx, maxy;
int idmaxx, idminx, idmaxy, idminy;
vector <punkt> d, e;
int daj(vector <punkt> &a)
{
	int malyx, duzyx, malyy, duzyy;
	malyx = malyy = 1000000000;
	duzyx = duzyy = -1000000000;
	for(auto it: a)
	{
		if(it.x > duzyx)
			duzyx = it.x;
		if(it.x < malyx)
			malyx = it.x;
		if(it.y > duzyy)
			duzyy = it.y;
		if(it.y < malyy)
			malyy = it.y;
	}
	return 2 * (duzyy - malyy) + 2 * (duzyx - malyx);
} 
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	minx = miny = 1000000000;
	maxx = maxy = -1000000000;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i].x >> t[i].y;
		if(t[i].x > maxx)
			idmaxx = i, maxx = t[i].x;
		if(t[i].x < minx)
			idminx = i, minx = t[i].x;
		if(t[i].y > maxy)
			idmaxy = i, maxy = t[i].y;
		if(t[i].y < miny)
			idminy = i, miny = t[i].y;
	}
	d.pb(t[idmaxx]);
	d.pb(t[idminx]);
	d.pb(t[idmaxy]);
	d.pb(t[idminy]);
	int X = daj(d);
	int ans = 0;
	for(int i = 0; 4 > i; ++i)
		for(int j = 0; 4 > j; ++j)
			for(int g = 1; n >= g; ++g)
			{
				e.clear();
				e.pb(d[i]);
				e.pb(d[j]);
				e.pb(t[g]);
				ans = max(ans, daj(e));
			}
	cout << ans << " ";
	for(int i = 4; n >= i; ++i)
		cout << X << " ";
	
	return 0;
}
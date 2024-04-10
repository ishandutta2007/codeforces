#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n;
vector <pair <int, int>> v;
int daj(int x, int y, int xx, int yy)
{
	printf("? %d %d %d %d\n", x, y, xx, yy);
	fflush(stdout);
	int e; scanf("%d", &e);
	return e & 1;
}
int main()
{
	int n;
	cin >> n;
	vector <int> col, wie;
	for(int i = 1; n - 1 >= i; ++i)
		if(daj(1, i, n, i))
			col.pb(i);
	if(ss(col) == 1)
		col.pb(n);
	if(ss(col))
	{
		for(auto it: col)
		{
			int lewo = 1;
			int prawo = n;
			while(prawo > lewo)
			{
				int mid = (lewo + prawo) / 2;
				if(daj(lewo, it, mid, it))
					prawo = mid;
				else
					lewo = mid + 1;
			}
			v.pb({lewo, it});
		}
	}
	for(int i = 1; n - 1 >= i; ++i)
		if(daj(i, 1, i, n))
			wie.pb(i);
	if(ss(wie) == 1)
		wie.pb(n);
	if(!ss(v))
	{
		for(auto it: wie)
		{
			int lewo = 1;
			int prawo = n;
			while(prawo > lewo)
			{
				int mid = (lewo + prawo) / 2;
				if(daj(it, lewo, it, mid))
					prawo = mid;
				else
					lewo = mid + 1;
			}
			v.pb({it, lewo});
		}
	}
	printf("! %d %d %d %d", v[0].fi, v[0].se, v[1].fi, v[1].se);
	fflush(stdout);
	
			
	return 0;
}
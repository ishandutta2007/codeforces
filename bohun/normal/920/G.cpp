#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int t, x, p, k;
vector < int > pr;
ll ans = 0;
ll zak = 0;
void go(int u ,int ri, int val, int siz)
{
	if(u == ri)
	{
		if(siz == 0)
			return ;
		ans += (zak/val) * ((siz % 2 == 1) ? 1 : -1);
		return ;
	}
	go(u + 1, ri, val * pr[u], siz + 1);
	go(u + 1, ri, val, siz);
}
ll daj(ll n, int val)
{
	zak = n;
	ans = 0;
	go(0, (int)pr.size(), 1, 0);
	return n - ans;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while(t--)
	{
		cin >> x >> p >> k;
		pr.clear();
		int val = p;
		for(ll i = 2; i * i <= val; ++i)
			{
				if(val % i == 0)
				{
					pr.push_back(i);
					while(val % i == 0)
						val /= i;
				}
			}
		if(val > 1)
			pr.push_back(val);
		ll od = daj(x, p);
		ll lewo = 1;
		ll prawo = 1e12;
		while(prawo > lewo)
		{
			ll mid = (lewo + prawo) / 2;
			if(daj(mid, p) - od >= k)
				prawo = mid;
			else
				lewo = mid + 1;
		}
		cout << lewo << endl;
	}
		
		
		
}
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
pair <int, int> t[100005];
ll wynik = 0;
bool cmp(pair <int, int> a, pair<int, int> b)
{
	return a.fi - a.se > b.fi - b.se;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; n >= i; ++i)
		scanf("%d %d", &t[i].fi, &t[i].se);
	sort(t + 1,t + n + 1, cmp);
	for(int i = 1; n >= i; ++i)
	{
		ll aa = (ll) (i - 1) * t[i].fi + (ll) (n - i) * t[i].se;
		wynik += aa;
	}
	cout << wynik;
		
	
	return 0;
}
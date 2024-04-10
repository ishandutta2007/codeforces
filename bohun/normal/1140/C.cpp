#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n, k;
pair < int, int > t[300005];
bool cmp(pair <int, int > a, pair <int, int > b)
{
	return b.se > a.se;
}
ll sum;
multiset <int> s;
int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 1; n >= i; ++i)
		scanf("%d %d", &t[i].fi, &t[i].se);
	sort(t + 1, t + n + 1, cmp);
	ll naj = 0;
	for(int i = n; i >= 1; --i)
	{
		s.insert(t[i].fi);
		sum += t[i].fi;
		if(ss(s) > k)
			sum -= *s.begin(), s.erase(s.begin());
		naj = max(naj, (ll) sum * t[i].se);
	}
	cout << naj;
		
	
	return 0;
}
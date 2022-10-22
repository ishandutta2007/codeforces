#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
int n, t[1000005];
stack < pair < int, int > > s;
int lewo[1000005], prawo[1000005];
ll ans = 0;
void go()
{
	t[0] = -1000000000;
	t[n + 1] = -1000000000;
	while(!s.empty())
		s.pop();
	for(int i = n; i >= 0; --i)
		{
			while(!s.empty() and t[i] < s.top().fi)
			{
				lewo[s.top().se] = i;
				s.pop();
			}
			s.push({t[i], i});
		}
	while(!s.empty())
		s.pop();
	for(int i = 1; n + 1 >= i; ++i)
		{
			while(!s.empty() and t[i] <= s.top().fi)
				{
					prawo[s.top().se] = i;
					s.pop();
				}
			s.push({t[i], i});
		}
	for(int i = 1; n >= i; ++i)
		ans -= (ll) t[i] * (i - lewo[i]) * (prawo[i] - i);
	
}
int main()
{	
	cin >> n;
	for(int i = 1; n >= i; ++i)
		scanf("%d", &t[i]);
	go();
	for(int i = 1; n >= i; ++i)
		t[i] *= -1;
	go();
	cout << ans;
	
	return 0;
}
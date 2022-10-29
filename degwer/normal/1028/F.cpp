#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
map<ll, vector<pii> >ma;
map<pii, int>ans;
int gcd(int a, int b)
{
	for (;;)
	{
		if (a == 0)return b;
		if (a < b)swap(a, b);
		a %= b;
	}
}
void add(int x, int y)
{
	ll s = (ll)x*(ll)x + (ll)y*(ll)y;
	vector<pii>se = ma[s];
	se.push_back(make_pair(x, y));
	for (int i = 0; i < se.size(); i++)
	{
		pii z = se[i];
		pii t = make_pair(z.first + x, z.second + y);
		ll g = gcd(t.first, t.second);
		t.first /= g, t.second /= g;
		if (z != make_pair(x, y))ans[t] += 2;
		else ans[t]++;
	}
	ma[s] = se;
}
void del(int x, int y)
{
	ll s = (ll)x*(ll)x + (ll)y*(ll)y;
	vector<pii>se = ma[s];
	for (int i = 0; i < se.size(); i++)
	{
		pii z = se[i];
		pii t = make_pair(z.first + x, z.second + y);
		ll g = gcd(t.first, t.second);
		t.first /= g, t.second /= g;
		if (z != make_pair(x, y))ans[t] -= 2;
		else ans[t]--;
	}
	vector<pii>r;
	for (int i = 0; i < se.size(); i++)if (se[i] != make_pair(x, y))r.push_back(se[i]);
	ma[s] = r;
}
int main()
{
	int num;
	scanf("%d", &num);
	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		int za, zx, zy;
		scanf("%d%d%d", &za, &zx, &zy);
		if (za == 1)add(zx, zy), cnt++;
		if (za == 2)del(zx, zy), cnt--;
		if (za == 3)
		{
			int g = gcd(zx, zy);
			printf("%d\n", cnt - ans[make_pair(zx / g, zy / g)]);
		}
	}
}
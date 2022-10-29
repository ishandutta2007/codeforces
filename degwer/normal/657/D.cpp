#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
class Q
{
public:
	ll x, y;
	Q() {}
	Q(ll x, ll y) :x(x), y(y) {}
	bool operator < (Q q)const
	{
		return x*q.y < y*q.x;
	}
	bool operator == (Q q)const
	{
		return x*q.y == y*q.x;
	}
};
typedef long double ld;
typedef pair<ld, ld>pdd;
typedef pair<ll, ll>pii;
typedef pair<ll, ld>pid;
typedef pair<ll, pdd>pidd;
ld eps = 1e-14;
int main()
{
	int num;
	scanf("%d", &num);
	vector<Q>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(Q(z, 0));
	}
	ll sum = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec[i].y = z;
		sum += z;
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	ld mini = 1.0;
	vector<pidd>ans;
	Q now = Q(0, 1);
	vector<Q>zv;
	ll s = 0;
	vec.push_back(Q(-1, 1));
	for (int i = 0; i <= num; i++)
	{
		if (now == vec[i])
		{
			zv.push_back(vec[i]);
		}
		else
		{
			ll zs = 0;
			for (int j = 0; j < zv.size(); j++)zs += zv[j].y;
			for (int j = 0; j < zv.size(); j++)
			{
				ans.push_back(make_pair(zv[j].x, make_pair(ld(s + zs)*ld(zv[j].x) / ld(sum), ld(s + zv[j].y)*ld(zv[j].x) / ld(sum))));
			}
			now = vec[i];
			s += zs;
			zv.clear();
			zv.push_back(vec[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size() - 1; i++)if (ans[i].first == ans[i + 1].first)ans[i + 1].second.second = min(ans[i].second.second, ans[i + 1].second.second);
	for (int i = ans.size() - 1; i >= 1; i--)if (ans[i].first == ans[i - 1].first)ans[i - 1].second.first = max(ans[i - 1].second.first, ans[i].second.first);
	for (int i = 0; i < ans.size() - 1; i++)
	{
		if (ans[i].first == ans[i + 1].first)continue;
		if (ans[i].second.second > ans[i + 1].second.first - eps)continue;
		mini = min(mini, ld(ans[i + 1].first - ans[i].first) / (ans[i + 1].second.first - ans[i].second.second));
	}
	printf("%lf\n", double(mini));
}
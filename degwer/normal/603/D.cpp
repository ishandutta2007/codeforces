#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long double ld;
typedef pair<ld,ld>P;
typedef long long ll;
ld eps = 1e-12;
ld pi = 3.1415926535897932384626433832;
int main()
{
	int num;
	scanf("%d", &num);
	vector<P>vec;
	ll cc = 0;
	for (int i = 0; i < num; i++)
	{
		double za, zb, zc;
		scanf("%lf%lf%lf", &za, &zb, &zc);
		if(fabs(zc)>eps)vec.push_back(make_pair(za*zc / (za*za + zb*zb), zb*zc / (za*za + zb*zb)));
		else cc++;
	}
	ll cnt = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		//printf("%Lf %Lf\n", vec[i].first, vec[i].second);
		vector<ld>v;
		for (int j = 0; j < vec.size(); j++)
		{
			if (i == j)continue;
			ld r = atan2(vec[i].first - vec[j].first, vec[i].second - vec[j].second);
			if (r < eps)r += pi;
			v.push_back(r);
		}
		sort(v.begin(), v.end());
		ld now = -1.0;
		ll s = 0;
		vector<ll>a;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] - now > eps)
			{
				now = v[j];
				a.push_back(s);
				s = 1;
			}
			else s++;
		}
		a.push_back(s);
		for (int j = 0; j < a.size(); j++)
		{
			cnt += a[j] * (a[j] - 1);
		}
	}
	if (cc != 2)printf("%I64d\n", cnt / 6);
	else printf("%I64d\n", cnt / 6 + num - 2);
}
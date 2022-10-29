#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
bool isok(vector<vector<ll> >vec)
{
	vector<ll>t;
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 8; j++)
		{
			ll x = 0;
			for (int k = 0; k < 3; k++)
			{
				x += (vec[i][k] - vec[j][k])*(vec[i][k] - vec[j][k]);
			}
			t.push_back(x);
		}
	}
	sort(t.begin(), t.end());
	if (t[0] == 0)return false;
	for (int i = 0; i < 12; i++)if (t[i] != t[0])return false;
	for (int i = 12; i < 24; i++)if (t[i] != t[0] * 2)return false;
	for (int i = 24; i < 28; i++)if (t[i] != t[0] * 3)return false;
	return true;
}
int main()
{
	vector<vector<ll> >vec;
	for (int i = 0; i < 8; i++)
	{
		vector<ll>v;
		for (int i = 0; i < 3; i++)
		{
			ll a;
			scanf("%I64d", &a);
			v.push_back(a);
		}
		vec.push_back(v);
	}
	for (int i = 0; i < 279936; i++)
	{
		int t = 1;
		for (int j = 0; j < 7; j++)
		{
			if (i%t == 0)next_permutation(vec[j].begin(), vec[j].end());
			t *= 6;
		}
		if (isok(vec))
		{
			printf("YES\n");
			for (int i = 0; i < 8; i++)
			{
				printf("%I64d %I64d %I64d\n", vec[i][0], vec[i][1], vec[i][2]);
			}
			return 0;
		}
	}
	printf("NO\n");
}
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
ll m1 = 1000000007;
ll m2 = 469762049;
ll b1 = 114514;
ll b2 = 810893;
ll rui1[100001], rui2[100001];
ll jou1[100001], jou2[100001];
vector<pii>get(string str)
{
	ll n1 = 1, n2 = 1;
	for (int i = 0; i <= str.size(); i++)
	{
		jou1[i] = n1;
		jou2[i] = n2;
		n1 = (n1*b1) % m1;
		n2 = (n2*b2) % m2;
	}
	for (int i = str.size() - 1; i >= 0; i--)
	{
		rui1[i] = (rui1[i + 1] + jou1[i] * str[i]) % m1;
		rui2[i] = (rui2[i + 1] + jou2[i] * str[i]) % m2;
	}
	vector<pii>ret;
	ll now1 = 0, now2 = 0;
	for (int i = 0; i <= str.size(); i++)
	{
		for (int j = 'a'; j <= 'z'; j++)
		{
			ll ha = (now1 + jou1[i] * j + rui1[i] * b1) % m1;
			ll hb = (now2 + jou2[i] * j + rui2[i] * b2) % m2;
			ret.push_back(make_pair(ha, hb));
		}
		if (i == str.size())break;
		now1 = (now1 + jou1[i] * str[i]) % m1;
		now2 = (now2 + jou2[i] * str[i]) % m2;
	}
	return ret;
}
int main()
{
	int num;
	scanf("%d", &num);
	string s1, s2;
	cin >> s1 >> s2;
	vector<pii>v1 = get(s1), v2 = get(s2);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	pii now = make_pair(-1, -1);
	int ret = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		if (now == v1[i])continue;
		now = v1[i];
		int low = lower_bound(v2.begin(), v2.end(), now) - v2.begin();
		if (low != v2.size())
		{
			if (v2[low] == now)ret++;
		}
	}
	printf("%d\n", ret);
}
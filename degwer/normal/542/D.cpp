#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
#define SIZE 1000000
map<pii, ll>memo;
vector<ll>pr;
bool ispr[SIZE+1];
vector<vector<ll> >dat;
bool isok(ll a)
{
	if (a == 0)return true;
	if (a < SIZE)return false;
	for (int i = 0; i < pr.size(); i++)
	{
		if (pr[i] * pr[i]>a)return true;
		if (a%pr[i] == 0)return false;
	}
	return true;
}
ll calc(ll t, int pt)
{
	if (memo.count(make_pair(t, pt)))return memo[make_pair(t, pt)];
	if (pt == dat.size())
	{
		if (isok(t - 1))return 1;
		else return 0;
	}
	ll sum = calc(t, pt + 1);
	for (int i = 0; i < dat[pt].size(); i++)
	{
		if (t%dat[pt][i] == 0)sum += calc(t / dat[pt][i], pt + 1);
	}
	return memo[make_pair(t, pt)] = sum;
}
int main()
{
	ll num;
	scanf("%I64d", &num);
	fill(ispr, ispr + SIZE+1, true);
	ispr[0] = ispr[1] = false;
	for (int i = 2; i <= SIZE; i++)
	{
		if (ispr[i])
		{
			for (int j = i + i; j <= SIZE; j += i)ispr[j] = false;
			pr.push_back(i);
		}
	}
	for (int i = 0; i < pr.size(); i++)
	{
		ll now = pr[i];
		vector<ll>z;
		for (;;)
		{
			if (now + 1 > num)break;
			if (num % (now + 1) == 0)
			{
				z.push_back(now + 1);
			}
			now *= pr[i];
		}
		if (!z.empty())
		{
			dat.push_back(z);
		}
	}
	printf("%I64d\n", calc(num, 0));
}
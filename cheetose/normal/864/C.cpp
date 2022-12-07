#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 987654321
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
vector<ll> v;
ll a, b, f, k;
int cnt()
{
	int c = 0;
	int n = v.size();
	ll now = 0;
	for (int i = 0; i < n; i++)
	{
		if (now + b < v[i])return -1;
		while (i<n && now + b >= v[i])i++;
		i--;
		c++;
		now = v[i];
	}
	return c-1;
}
int main() {
	scanf("%I64d%I64d%I64d%I64d", &a, &b, &f, &k);
	v.push_back(f);
	for (ll i = 1; i < k; i++)
	{
		if (i & 1)v.push_back(v[i - 1] + 2*(a - f));
		else v.push_back(v[i - 1] + 2*f);
	}
	v.push_back(a*k);
	printf("%d", cnt());
}
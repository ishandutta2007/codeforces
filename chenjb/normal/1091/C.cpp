#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <cassert>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n;
vector<long long> ans;
int main()
{	
	cin>>n;
	ans.clear();
	rep(i,n)
	{
		if (1ll*i*i>n)break;
		if (n%i)continue;
		int k=i;
		long long sub=1ll*(long long)(n+2-k)*(long long)(n/k)/2;
		ans.pb(sub);
		if (1ll*i*i==n)continue;
		k=n/i;
		sub=1ll*(long long)(n+2-k)*(long long)(n/k)/2;
		ans.pb(sub);
	}
	sort(ans.begin(),ans.end());
	for(auto p:ans)printf("%lld ",p); puts("");
	return 0;
}
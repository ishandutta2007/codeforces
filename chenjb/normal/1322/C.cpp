#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=1100000;
int n,m;
long long c[N];
long long w1[N];
long long w2[N];
long long sum1[N],sum2[N];
long long gcd(long long x,long long y) { return (!y)?x:gcd(y,x%y); }
mt19937 rnd(time(NULL));
map<pair<long long,long long>,long long> dic;
long long getrand()
{
	return 1ll*(rand()+1)*(rand()+1)*(rand()+1)%2147483647;
}
int main()
{
	srand(time(0));
	int T;
	cin>>T;
	while (T--)
	{
		dic.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
		for(int i=1;i<=n;i++)w1[i]=(rnd()<<rnd())^rnd(),sum1[i]=0;
		for(int i=1;i<=n;i++)w2[i]=(rnd()<<rnd())^rnd(),sum2[i]=0;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			sum1[y]+=w1[x];
			sum2[y]+=w2[x];
		}
		for(int i=1;i<=n;i++)
		{
			//cout<<sum1[i]<<" "<<sum2[i]<<endl;
			auto t=mp(sum1[i],sum2[i]);
			dic[t]+=c[i];
		}
		long long ans=0;
		for(auto p:dic)
			if (p.first.first!=0&&p.first.second!=0)ans=gcd(ans,p.second);
		printf("%lld\n",ans);
	}
	return 0;
}
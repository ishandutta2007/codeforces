

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
#define INF 2000000000
#define FOR(i,x,n) for(int i=x;i<=n;i++)
#define REV(i,x,n) for(int i=x;i>=n;i--)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define LL long long
#define test int T;scanf("%d",&T);while(T--)
#define pb push_back
#define b() begin()
#define e() end()
#define s() size()
#define cl() clear()






int minm[200],cost[200];
int main()
{
memset(minm,1,sizeof(minm));
int m,n;
si(n);si(m);
while(m--)
          {
          int l,r,t,c;
          si(l);si(r);si(t);si(c);
          FOR(i,l,r)
          if(t<minm[i])
          {minm[i]=t;
          cost[i]=c;}
          }

int ans=0;
FOR(i,1,n)
{
//cout<<minm[i]<<endl;
//cout<<cost[i]<<endl;
ans+=cost[i];}


printf("%d\n",ans);
//cin>>ans;
return 0;
}
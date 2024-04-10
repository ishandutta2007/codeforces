#include<bits/stdc++.h>
#define INF 1000000000000LL
#define LL long long
#define F first
#define S second
using namespace std;
const int maxn=1000000+10 ;
 
bool vis[maxn] ;
int p[maxn],pcnt=0 ;
void prime()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1  ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++pcnt]=i ;
}
 
bool isp(LL x)
{
    if(x<maxn) return !vis[x] ;
    for(int i=1;i<=pcnt;i++) if((x%p[i])==0)
        return 0 ;
    return 1 ;
}
 
map<LL,LL> good ;
map<LL,vector<LL> > mp ;
 
LL isgood(LL x)
{
    auto it=good.find(x) ;
    if(it!=good.end()) return it->S ;
    return (x>=maxn && isp(x-1)) ? x-1 : 0 ;
}
 
LL n ;
LL di[maxn] ;
int dcnt ;
map<LL,LL> dp ;
main()
{
    prime() ;
    for(int i=1;i<=pcnt;i++)
        for(LL j=p[i];j<=INF;j*=p[i])
            good[j+1]=p[i] ;
 
    scanf("%I64d",&n) ;
    for(LL i=1;i*i<=n;i++) if((n%i)==0)
    {
        di[dcnt++]=i ;
        LL x=isgood(i) ;
        if(x) mp[x].push_back(i) ;
        if(i*i==n) continue ;
 
        di[dcnt++]=n/i ;
        x=isgood(n/i) ;
        if(x) mp[x].push_back(n/i) ;
    }
 
    sort(di,di+dcnt) ;
    dp[1]=1 ;
    for(auto it : mp) for(int i=dcnt-1;i>=0;i--)
        for(auto j : it.S) if(di[i]%j==0)
        dp[di[i]]+=dp[di[i]/j] ;
 
    printf("%I64d\n",dp[n]) ;
}
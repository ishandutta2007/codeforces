#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <cassert>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int a[5100],n;
bool g[5200][5200];
map<pair<long long,long long>,int> dic;
vector<int> save;
int cnt;
int ans[5200];
bool f[5200];
void decompose(int p)
{
    if (a[p]==0)return;
    save.clear();
    if (a[p]<0){ save.pb(1); a[p]=-a[p];}
    int maxp=(int)sqrt(a[p])+1;
    for(int i=2;i<=maxp;i++)
        if (a[p]%i==0)
        {
            int cnt=0;
            while (a[p]%i==0)a[p]/=i,cnt++;
            if (cnt&1)save.pb(i+2);
        }
    if (a[p]!=1)save.pb(a[p]+2);
    sort(save.begin(),save.end());
    long long p1=0,p2=0;
    for(auto x:save)p1=(p1*1000000007+x)%998244353,p2=(p2*998244353+x)%1000000009;
    if (dic.find(mp(p1,p2))==dic.end())dic[mp(p1,p2)]=++cnt;
    a[p]=dic[mp(p1,p2)];
}
int main()
{
    cin>>n;
    dic.clear();
    cnt=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)decompose(i);
    for(int i=1;i<=n;i++)ans[i]=0;
    for(int i=1;i<=n;i++)
    {
        int now=0;
        for(int j=1;j<=cnt;j++)f[j]=0;
        f[0]=1; 
        for(int j=i;j<=n;j++)
        {
            if (!f[a[j]])now++;
            f[a[j]]=1;
            if (now==0)ans[1]++; else ans[now]++;
        }
    }
    for(int i=1;i<=n;i++)printf("%d%c",ans[i],i==n?'\n':' ');
}
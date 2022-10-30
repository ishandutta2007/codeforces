#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int n;
long long k;
int p[410000];
map<int,int> dic;
pair<int,int> a[410000];
int pre[510000],suf[510000];
int main()
{
    scanf("%d%d",&n,&k);k*=8;
    k=k/n;if(k>30)k=30;
    k=1<<k;
    dic.clear();
    rep(i,n){ int x; scanf("%d",&x); dic[x]++; }
    n=0;
    for(auto p:dic)a[++n]=mp(p.first,p.second);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i].second;
    for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i].second;
    //for(int i=1;i<=n;i++)cout<<pre[i]<<" "; puts("");
    int ans=2147483647;
   // cout<<k<<endl;
    for(int l=1;l<=n;l++)
    {
        int r=min(1ll*n,l+k-1);
        //cout<<l<<" "<<r<<" "<<pre[l-1]+suf[r+1]<<endl;
        ans=min(ans,pre[l-1]+suf[r+1]);
    }
    cout<<ans<<endl;
    return 0;
}
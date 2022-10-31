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
#define magic 300
#define M 500000
#define N 200;
using namespace std;
map<int,pair<int,int> > dic;
int ans,ansp,n;
int a[310000],pre[310000];
vector<int> save;
int main()
{
    cin>>n;
    ans=0; 
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int t,p;
        if (dic.find(a[i]-1)==dic.end())t=1,pre[i]=0;
        else t=dic[a[i]-1].first+1,pre[i]=dic[a[i]-1].second;
        if (t>ans)ans=t,ansp=i;
        if (dic.find(a[i])==dic.end())dic[a[i]]=mp(t,i);
        else if (dic[a[i]].first<t)dic[a[i]]=mp(t,i);
    }
    cout<<ans<<endl;
    save.clear();
    int now=ansp;
    while (now!=0)
    {
        save.pb(now);
        now=pre[now];
    }
    reverse(save.begin(),save.end());
    for(int i=0;i<ans;i++)printf("%d%c",save[i],i==ans-1?'\n':' ');
    return 0;
}
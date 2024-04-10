#include<bits/stdc++.h>
#define N 300000
using namespace std;
int T,n,m,a[N+5];
set<pair<int,int> > s;
vector<int> v[N+5],p;
map<int,int> cnt;
inline int calc(const vector<int> &v1,const vector<int> &v2)
{
    vector<unsigned> now(v1.size());
    priority_queue<pair<int,int> > q;
    for(unsigned i=0;i<v1.size();++i)
        q.push({v1[i]+v2[0],i});
    while(!q.empty())
    {
        int x=q.top().second;q.pop();
        if(!s.count({v1[x],v2[now[x]]}) && v1[x] !=v2[now[x]]) return v1[x]+v2[now[x]];
        if((++now[x])<v2.size()) q.push({v1[x]+v2[now[x]],x});
    }
    return 0;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        s.clear(),cnt.clear(),p.clear();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i)
            scanf("%d",a+i),++cnt[a[i]],v[i].clear();
        for(int i=1,x,y;i<=m;++i)
        {
            scanf("%d %d",&x,&y);
            s.insert({x,y}),s.insert({y,x});
        }
        for(auto x:cnt) v[x.second].push_back(x.first);
        for(int i=1;i<=n;++i)
            if(!v[i].empty()) p.push_back(i),
            sort(v[i].begin(),v[i].end(),greater<int>());
        long long ans=0;
        for(unsigned i=0;i<p.size();++i)
            for(unsigned j=i;j<p.size();++j)
                ans=max(ans,1ll*(p[i]+p[j])*calc(v[p[i]],v[p[j]]));
        printf("%lld\n",ans);
    }
    return 0;
}
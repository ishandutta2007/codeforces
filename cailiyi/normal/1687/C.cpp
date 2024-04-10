#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,m,a[N+5],l[N+5],r[N+5],cnt,siz[N+5];
bool sf[N+5];
vector<int> v[N+5];
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;++i) scanf("%d",a+i),sf[i]=0;
        long long now=0;
        sf[0]=1,cnt=1;
        set<int> s;
        for(int i=1,b;i<=n;++i)
        {
            scanf("%d",&b),now+=a[i]-b,v[i].clear();
            if(!now) sf[i]=1;
            else s.insert(i);
        }
        queue<int> q;
        for(int i=1;i<=m;++i)
        {
            scanf("%d %d",l+i,r+i),siz[i]=0;
            if(!sf[l[i]-1]) ++siz[i],v[l[i]-1].push_back(i);
            if(!sf[r[i]]) ++siz[i],v[r[i]].push_back(i);
            if(!siz[i]) q.push(i);
        }
        while(!s.empty() && !q.empty())
        {
            int p=q.front();q.pop();
            for(set<int>::iterator it=s.lower_bound(l[p]);it!=s.end() && *it<=r[p];s.erase(it++))
                for(int x:v[*it]) if(!(--siz[x])) q.push(x);
        }
        puts(s.empty()?"YES":"NO");
    }
    return 0;
}
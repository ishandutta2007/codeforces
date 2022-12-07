#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=5e5+10, inf=2e18;
int p, dot[sz*4];
void add(int nu, int l, int r)
{
    if(l==r) dot[nu]=1;
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) add(nu*2, l, mid);
        else add(nu*2+1, mid+1, r);
        dot[nu]=dot[nu*2]+dot[nu*2+1];
    }
}
int va;
int que(int nu, int l, int r)
{
    if(l==r) return l;
    else
    {
        int mid=(l+r)>>1;
        if(dot[nu*2]>=va) return que(nu*2, l, mid);
        else
        {
            va-=dot[nu*2];
            return que(nu*2+1, mid+1, r);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, qq;
    cin>>n>>m>>qq;
    int q[m+1];
    for(int a=0; a<=m; a++) q[a]=0;
    q[0]=inf/m;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        q[x]++;
    }
    map <int, vector <int> > ma;
    for(int a=0; a<=m; a++) ma[q[a]].push_back(a);
    pair <int, int> qu[qq];
    for(int a=0; a<qq; a++)
    {
        scanf("%lld", &qu[a].first), qu[a].second=a;
    }
    sort(qu, qu+qq);
    auto it=ma.begin();
    int su=0, cnt=0, an[qq];
    for(int a=0; a<(*it).second.size(); a++)
    {
        p=(*it).second[a], cnt++, add(1, 0, m);
    }
    for(int a=0; a<qq; a++)
    {
        int nu=qu[a].first;
        nu-=su+n;
        while(1)
        {
            auto it2=it;
            it2++;
            if(((*it2).first-(*it).first)*cnt<nu)
            {
                su+=((*it2).first-(*it).first)*cnt;
                nu-=((*it2).first-(*it).first)*cnt;
                it++;
                for(int b=0; b<(*it).second.size(); b++)
                {
                    p=(*it).second[b], cnt++, add(1, 0, m);
                }
            }
            else break;
        }
        va=(nu-1)%cnt+1;
        an[qu[a].second]=que(1, 0, m);
    }
    for(int a=0; a<qq; a++) printf("%lld\n", an[a]);
}
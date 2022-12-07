#include <bits/stdc++.h>
#define iter map <int, int>::iterator
using namespace std;
const int sz=3e5+10, inf=1e9;
vector <int> sv[sz], sp[sz];
vector <pair <int, int> > di[sz];
struct line
{
    int x, yl, yr, nu;
};
vector <line> lines;
map <int, int> lse[sz], rse[sz];
void ins(map <int, int> &se, int p, int va)
{
    iter rit=se.upper_bound(p), it;
    it=rit;
    if(va<(*it).second+((*it).first-p))
    {
        bool fo=0;
        while(it!=se.begin())
        {
            it--;
            int cva=(*it).second, cp=(*it).first;
            if(va+(p-cp)>cva)
            {
                if(cp==p) fo=1;
                it++;
                break;
            }
        }
        se.erase(it, rit);
        if(fo==0) se[p]=va;
    }
}
int que(map <int, int> &se, int p)
{
    iter it=se.lower_bound(p);
    return (*it).second+((*it).first-p);
}
int si[sz];
void siz(int v, int pr)
{
    si[v]=lines[v].yr-lines[v].yl+1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            siz(ne, v);
            si[v]+=si[ne];
        }
    }
}
int find_ce(int v, int pr, int qq)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr and si[ne]>qq/2) return find_ce(ne, v, qq);
    }
    if(pr!=-1) si[pr]=qq-si[v];
    return v;
}
void dfs2(int v, int pr, int ce)
{
    int lnu=lines[pr].nu, rnu=lines[pr].nu+(lines[pr].yr-lines[pr].yl);
    for(int a=0; lines[v].yl+a<=lines[v].yr; a++)
    {
        int y=lines[v].yl+a, nu=lines[v].nu+a;
        if(y>lines[pr].yr)
        {
            di[nu].push_back(make_pair(y-lines[pr].yr+di[rnu].back().first+1, di[rnu].back().second));
        }
        else if(y<lines[pr].yl)
        {
            di[nu].push_back(make_pair(lines[pr].yl-y+di[lnu].back().first+1, di[lnu].back().second));
        }
        else
        {
            int nu2=lines[pr].nu+(y-lines[pr].yl);
            di[nu].push_back(make_pair(di[nu2].back().first+1, di[nu2].back().second));
        }
        sp[nu].push_back(ce);
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs2(ne, v, ce);
    }
}
void dfs(int v, int qq)
{
    siz(v, -1);
    int ce=find_ce(v, -1, qq);
    for(int a=0; lines[ce].yl+a<=lines[ce].yr; a++)
    {
        int nu=lines[ce].nu+a;
        di[nu].push_back(make_pair(0, a));
        sp[nu].push_back(ce);
    }
    for(int a=0; a<sv[ce].size(); a++) dfs2(sv[ce][a], ce, ce);
    lse[ce][inf]=inf;
    rse[ce][inf]=inf;
    for(int a=0; a<sv[ce].size(); a++)
    {
        int ne=sv[ce][a];
        for(int b=0; b<sv[ne].size(); b++)
        {
            if(sv[ne][b]==ce) sv[ne].erase(sv[ne].begin()+b);
        }
        dfs(ne, si[ne]);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> ar[n];
    pair <pair <int, int>, int> ar2[n];
    map <pair <int, int>, int> ma;
    for(int a=0; a<n; a++) scanf("%d%d", &ar[a].first, &ar[a].second);
    sort(ar, ar+n);
    int yk=0;
    while(yk<n)
    {
        lines.push_back({ar[yk].first, ar[yk].second, ar[yk].second-1, yk});
        while(yk<n)
        {
            if(ar[yk].first==lines.back().x and ar[yk].second==lines.back().yr+1)
            {
                ma[ar[yk]]=yk;
                ar2[yk].first.first=ar[yk].second, ar2[yk].first.second=ar[yk].first, ar2[yk].second=lines.size()-1;
                lines.back().yr++, yk++;
            }
            else break;
        }
    }
    sort(ar2, ar2+n);
    for(int a=0; a+1<n; a++)
    {
        int y1=ar2[a].first.first, x1=ar2[a].first.second, nu1=ar2[a].second;
        int y2=ar2[a+1].first.first, x2=ar2[a+1].first.second, nu2=ar2[a+1].second;
        if(y1==y2 and x1+1==x2 and (lines[nu1].yr==y1 or lines[nu2].yr==y2))
        {
            sv[nu1].push_back(nu2);
            sv[nu2].push_back(nu1);
        }
    }
    dfs(0, n);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ty, x, y;
        scanf("%d%d%d", &ty, &x, &y);
        int nu=ma[make_pair(x, y)];
        if(ty==1)
        {
            for(int a=0; a<sp[nu].size(); a++)
            {
                int i=sp[nu][a], va=di[nu][a].first, p=di[nu][a].second;
                ins(lse[i], p, va);
                ins(rse[i], -p, va);
            }
        }
        else
        {
            int an=inf;
            for(int a=0; a<sp[nu].size(); a++)
            {
                int i=sp[nu][a], va=di[nu][a].first, p=di[nu][a].second, re=inf;
                re=min(re, va+que(lse[i], p));
                re=min(re, va+que(rse[i], -p));
                an=min(an, re);
            }
            if(an==inf) printf("-1\n");
            else printf("%d\n", an);
        }
    }
}
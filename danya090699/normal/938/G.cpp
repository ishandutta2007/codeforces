#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int lg, rg, an[sz], zq=0;
vector <pair <pair <int, int>, int> > dot[sz*4], zap[sz];
pair <pair <int, int>, int> cu;
void ins(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[nu].push_back(cu);
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        ins(nu*2, l, mid);
        ins(nu*2+1, mid+1, r);
    }
}
pair <int, int> p[sz];
vector <pair <int, int> > oper;
int si[sz], basis[30];
pair <int, int> get_pr(int v)
{
    if(p[v].first==v) return p[v];
    else
    {
        pair <int, int> re=get_pr(p[v].first);
        re.second^=p[v].second;
        return re;
    }
}
void que(int nu, int l, int r)
{
    for(int a=0; a<dot[nu].size(); a++)
    {
        int u=dot[nu][a].first.first, v=dot[nu][a].first.second, pr=dot[nu][a].second;
        pair <int, int> v1=get_pr(u), v2=get_pr(v);
        if(v1.first==v2.first)
        {
            int x=v1.second^v2.second^pr;
            for(int b=29; b>=0; b--) x=min(x, x^basis[b]);
            if(x==0) oper.push_back(make_pair(-1, -1));
            else
            {
                for(int b=29; b>=0; b--)
                {
                    if(x>=(1<<b))
                    {
                        basis[b]=x;
                        oper.push_back(make_pair(b, -1));
                        break;
                    }
                }
            }
        }
        else
        {
            if(si[v1.first]<si[v2.first])
            {
                swap(u, v), swap(v1, v2);
            }
            p[v2.first].first=v1.first;
            p[v2.first].second=v1.second^v2.second^pr;
            si[v1.first]+=si[v2.first];
            oper.push_back(make_pair(v1.first, v2.first));
        }
    }
    if(l==r)
    {
        for(int a=0; a<zap[l].size(); a++)
        {
            int u=zap[l][a].first.first, v=zap[l][a].first.second, i=zap[l][a].second;
            an[i]=get_pr(u).second^get_pr(v).second;
            for(int b=29; b>=0; b--) an[i]=min(an[i], an[i]^basis[b]);
        }
    }
    else
    {
        int mid=(l+r)>>1;
        que(nu*2, l, mid);
        que(nu*2+1, mid+1, r);
    }
    for(int a=0; a<dot[nu].size(); a++)
    {
        if(oper.back().first!=-1)
        {
            if(oper.back().second!=-1)
            {
                int u=oper.back().first, v=oper.back().second;
                si[u]-=si[v], p[v].first=v, p[v].second=0;
            }
            else basis[oper.back().first]=0;
        }
        oper.pop_back();
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cin>>n>>m;
    map <pair <int, int>, int> ma, ma2;
    for(int a=0; a<m; a++)
    {
        pair <int, int> re;
        int pr;
        scanf("%d%d%d", &re.first, &re.second, &pr);
        re.first--, re.second--;
        ma[re]=0;
        ma2[re]=pr;
    }
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int ty;
        pair <int, int> re;
        scanf("%d%d%d", &ty, &re.first, &re.second);
        re.first--, re.second--;
        if(ty==1)
        {
            int pr;
            scanf("%d", &pr);
            ma[re]=a;
            ma2[re]=pr;
        }
        if(ty==2)
        {
            lg=ma[re], rg=a, cu=make_pair(re, ma2[re]);
            ma.erase(re);
            ins(1, 0, q);
        }
        if(ty==3)
        {
            zap[a].push_back(make_pair(re, zq)), zq++;
        }
    }
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        pair <int, int> re=(*it).first;
        lg=(*it).second, rg=q, cu=make_pair(re, ma2[re]);
        ins(1, 0, q);
    }
    for(int a=0; a<n; a++)
    {
        p[a]=make_pair(a, 0), si[a]=1;
    }
    que(1, 0, q);
    for(int a=0; a<zq; a++) printf("%d\n", an[a]);
}
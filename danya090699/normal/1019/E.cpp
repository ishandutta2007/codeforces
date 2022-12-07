#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
map <int, pair <int, int> > sv[sz];
int n, m;
void build(int v, int pr)
{
    int prev=-1;
    vector <pair <int, pair <int, int> > > sp;
    for(auto it=sv[v].begin(); it!=sv[v].end(); it++) sp.push_back(make_pair((*it).first, (*it).second));
    for(int a=0; a<sp.size(); a++)
    {
        int ne=sp[a].first;
        pair <int, int> va=sp[a].second;
        if(ne!=pr)
        {
            if(prev!=-1)
            {
                sv[v].erase(ne), sv[ne].erase(v);
                sv[n][prev]=make_pair(0, 0), sv[prev][n]=make_pair(0, 0);
                sv[n][ne]=va, sv[ne][n]=va;
                prev=n, n++;
            }
            else prev=v;
            build(ne, prev);
        }
    }
}
int si[sz];
void siz(int v, int pr)
{
    si[v]=1;
    for(auto it=sv[v].begin(); it!=sv[v].end(); it++)
    {
        int ne=(*it).first;
        if(ne!=pr)
        {
            siz(ne, v), si[v]+=si[ne];
        }
    }
}
int find_ce(int v, int pr, int q)
{
    for(auto it=sv[v].begin(); it!=sv[v].end(); it++)
    {
        int ne=(*it).first;
        if(ne!=pr)
        {
            if(si[ne]>q/2) return find_ce(ne, v, q);
        }
    }
    if(pr!=-1) si[pr]=q-si[v];
    return v;
}
void dfs2(int v, int pr, long long k, long long b, vector <pair <long long, long long> > &sp)
{
    sp.push_back(make_pair(k, b));
    for(auto it=sv[v].begin(); it!=sv[v].end(); it++)
    {
        int ne=(*it).first;
        pair <int, int> va=(*it).second;
        if(ne!=pr) dfs2(ne, v, k+va.first, b+va.second, sp);
    }
}
struct el
{
    long long l, k, b;
};
vector <pair <long long, long long> > gsp;
long long de(long long x, long long y){return x/y+(x%y>0);}
void ins(long long k, long long b, vector <el> &hull)
{
    bool fo=0;
    while(hull.size())
    {
        long long k2=hull.back().k, b2=hull.back().b, l=hull.back().l;
        if(k==k2)
        {
            if(b>b2) hull.pop_back();
            else
            {
                fo=1;
                break;
            }
        }
        else
        {
            if(b<b2)
            {
                long long l2=de(b2-b, k-k2);
                if(l2>l)
                {
                    if(l2<m) hull.push_back({l2, k, b});
                    fo=1;
                    break;
                }
                else hull.pop_back();
            }
            else hull.pop_back();
        }
    }
    if(fo==0) hull.push_back({0, k, b});
}
void dfs(int v, int q)
{
    if(q>1)
    {
        siz(v, -1);
        int ce=find_ce(v, -1, q);
        int ce2, masi=0;
        for(auto it=sv[ce].begin(); it!=sv[ce].end(); it++)
        {
            int ne=(*it).first;
            if(si[ne]>masi)
            {
                masi=si[ne], ce2=ne;
            }
        }
        int cek=sv[ce][ce2].first, ceb=sv[ce][ce2].second;
        sv[ce].erase(ce2), sv[ce2].erase(ce);
        vector <pair <long long, long long> > sp[2];
        vector <el> hull[2];
        dfs2(ce, -1, 0, 0, sp[0]);
        dfs2(ce2, -1, 0, 0, sp[1]);
        for(int i=0; i<2; i++)
        {
            sort(sp[i].begin(), sp[i].end());
            for(int a=0; a<sp[i].size(); a++) ins(sp[i][a].first, sp[i][a].second, hull[i]);
        }
        int yk=0, yk2=0;
        while(yk<hull[0].size() and yk2<hull[1].size())
        {
            long long k1=hull[0][yk].k, b1=hull[0][yk].b, r1=m;
            if(yk+1<hull[0].size()) r1=hull[0][yk+1].l;
            long long k2=hull[1][yk2].k, b2=hull[1][yk2].b, r2=m;
            if(yk2+1<hull[1].size()) r2=hull[1][yk2+1].l;

            gsp.push_back(make_pair(k1+k2+cek, b1+b2+ceb));

            if(r1==min(r1, r2)) yk++;
            if(r2==min(r1, r2)) yk2++;
        }

        dfs(ce, q-si[ce2]);
        dfs(ce2, si[ce2]);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=0; a<n-1; a++)
    {
        int u, v, k, b;
        scanf("%d%d%d%d", &u, &v, &k, &b);
        u--, v--;
        sv[u][v]=make_pair(k, b);
        sv[v][u]=make_pair(k, b);
    }
    build(0, -1);
    dfs(0, n);
    vector <el> hull;
    sort(gsp.begin(), gsp.end());
    if(gsp.size()==0) gsp.push_back(make_pair(0, 0));
    for(int a=0; a<gsp.size(); a++) ins(gsp[a].first, gsp[a].second, hull);
    for(int a=0; a<hull.size(); a++)
    {
        long long l=hull[a].l, k=hull[a].k, b=hull[a].b, r=m;
        if(a+1<hull.size()) r=hull[a+1].l;
        for(int i=l; i<r; i++) printf("%lld ", k*i+b);
    }
}
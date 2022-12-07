//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define iter set <int>::iterator
using namespace std;
const int bl=1100, sz=1e5+10, sz2=500, inf=1e9;
int l[sz], r[sz], ar[sz];
vector <int> sq[sz2], sq2[sz2], pref[sz2], pref2[sz2];
set <int> se[sz];
bool comp(int a, int b){return l[a]<l[b];}
bool comp2(int a, int b){return r[a]>r[b];}
void build(vector <int> &ve, vector <int> &re)
{
    re[0]=ve[0];
    for(int a=1; a<ve.size(); a++) re[a]=re[a-1]+ve[a];
}
void recalc(int nu, int p)
{
    int n=sq[nu].size();
    for(int a=0; a<n-1; a++) if(sq[nu][a]==p) swap(sq[nu][a], sq[nu][a+1]);
    for(int a=n-1; a>0; a--) if(l[sq[nu][a]]<l[sq[nu][a-1]]) swap(sq[nu][a], sq[nu][a-1]);
    build(sq[nu], pref[nu]);
}
void recalc2(int nu, int p)
{
    int n=sq2[nu].size();
    for(int a=0; a<n-1; a++) if(sq2[nu][a]==p) swap(sq2[nu][a], sq2[nu][a+1]);
    for(int a=n-1; a>0; a--) if(r[sq2[nu][a]]>r[sq2[nu][a-1]]) swap(sq2[nu][a], sq2[nu][a-1]);
    build(sq2[nu], pref2[nu]);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        sq[a/bl].push_back(a);
        sq2[a/bl].push_back(a);
        se[ar[a]].insert(a);
    }
    for(int a=0; a<sz; a++)
    {
        for(iter it=se[a].begin(); it!=se[a].end(); it++)
        {
            if(it==se[a].begin()) l[*it]=-1;
            iter it2=it;
            it2++;
            if(it2!=se[a].end())
            {
                r[*it]=*it2, l[*it2]=*it;
            }
            else r[*it]=inf;
        }
    }
    for(int a=0; a*bl<n; a++)
    {
        sort(sq[a].begin(), sq[a].end(), comp);
        pref[a].resize(sq[a].size());
        build(sq[a], pref[a]);
        sort(sq2[a].begin(), sq2[a].end(), comp2);
        pref2[a].resize(sq2[a].size());
        build(sq2[a], pref2[a]);
    }
    for(int a=0; a<m; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==1)
        {
            int p, x;
            scanf("%d%d", &p, &x);
            p--;
            if(x!=ar[p])
            {
                if(l[p]!=-1)
                {
                    r[l[p]]=r[p], recalc2(l[p]/bl, l[p]);
                }
                if(r[p]!=inf)
                {
                    l[r[p]]=l[p], recalc(r[p]/bl, r[p]);
                }
                se[ar[p]].erase(p), ar[p]=x, se[x].insert(p);
                iter it=se[x].find(p);
                if(it!=se[x].begin())
                {
                    it--;
                    int p2=*it;
                    r[p2]=p, recalc2(p2/bl, p2);
                    l[p]=p2;
                    it++;

                }
                else l[p]=-1;
                recalc(p/bl, p);
                it++;
                if(it!=se[x].end())
                {
                    int p2=*it;
                    l[p2]=p, recalc(p2/bl, p2);
                    r[p]=p2;
                    it--;
                }
                else r[p]=inf;
                recalc2(p/bl, p);
            }
        }
            else
            {
                int lg, rg;
                scanf("%d%d", &lg, &rg);
                long long an=0;
                lg--, rg--;
                for(int b=0; b*bl<n; b++)
                {
                    int cl=b*bl, cr=b*bl+sq[b].size()-1;
                    if(!(lg>cr or rg<cl))
                    {
                        if(cl>=lg and cr<=rg)
                        {
                            l[n]=lg, r[n]=rg;
                            int p=lower_bound(sq[b].begin(), sq[b].end(), n, comp)-sq[b].begin();
                            if(p>0) an-=pref[b][p-1];
                            p=lower_bound(sq2[b].begin(), sq2[b].end(), n, comp2)-sq2[b].begin();
                            if(p>0) an+=pref2[b][p-1];
                        }
                        else
                        {
                            for(int c=0; c<sq[b].size(); c++)
                            {
                                if(sq[b][c]>=lg and sq[b][c]<=rg)
                                {
                                    int p=sq[b][c];
                                    if(l[p]<lg) an-=p;
                                }
                                if(sq2[b][c]>=lg and sq2[b][c]<=rg)
                                {
                                    int p=sq2[b][c];
                                    if(r[p]>rg) an+=p;
                                }
                            }
                        }
                    }
                }
                printf("%lld\n", an);
            }
    }
}
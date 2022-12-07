#include <bits/stdc++.h>
#define iter map <int, pair <int, int> >::iterator
using namespace std;
const int sz=2e4;
struct pt
{
    int x, y;
};
pt ar[sz];
vector <int> sv[sz];
bool comp(int a, int b){return ar[a].y<ar[b].y;}
bool comp2(int a, int b){return ar[a].x<ar[b].x;}
bool us[sz];
void dfs(int v)
{
    us[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, xl, yl, xr, yr, q=0;
    cin>>xl>>yr>>xr>>yl>>n;
    for(int a=0; a<n; a++) cin>>ar[a].x>>ar[a].y;
    vector <int> ve, ve2;
    for(int a=0; a<n; a++)
    {
        pt p1=ar[a], p2=ar[(a+1)%n];
        if(p1.y==p2.y and p1.y>yl and p1.y<yr and min(p1.x, p2.x)<=xl and max(p1.x, p2.x)>xl) ve2.push_back(a);
        if(p1.x==p2.x and p1.x>xl and p1.x<xr and max(yl, min(p1.y, p2.y))<min(yr, max(p1.y, p2.y))) ve.push_back(a);
    }
    map <int, pair <int, int> > se;
    sort(ve2.begin(), ve2.end(), comp);
    if(ve2.size()==0)
    {
        bool inter=0;
        for(int a=1; a<n; a++)
        {
            pt p1=ar[a], p2=ar[(a+1)%n];
            if(p1.y==p2.y and p1.y>=yr and min(p1.x, p2.x)<=xl and xl<max(p1.x, p2.x)) inter^=1;
        }
        if(inter)
        {
            se[yl]=make_pair(yr, 0), q++;
        }
    }
    else
    {
        for(int a=0; a<ve2.size(); a++)
        {
            pt p1=ar[ve2[a]], p2=ar[(ve2[a]+1)%n];
            if(p1.x>p2.x)
            {
                int lg=yl;
                if(a>0) lg=ar[ve2[a-1]].y;
                se[lg]=make_pair(p1.y, q), q++;
            }
            else if(a+1==ve2.size())
            {
                se[p1.y]=make_pair(yr, q), q++;
            }
        }
    }
    sort(ve.begin(), ve.end(), comp2);
    for(int a=0; a<ve.size(); a++)
    {
        pt p1=ar[ve[a]], p2=ar[(ve[a]+1)%n];
        int lg=max(yl, min(p1.y, p2.y)), rg=min(yr, max(p1.y, p2.y));
        if(p1.y>p2.y)
        {
            iter itr=se.upper_bound(lg), itl;
            if(itr!=se.begin())
            {
                itl=itr, itl--;
                int lg2=(*itl).first, rg2=(*itl).second.first, nu=(*itl).second.second;
                if(rg2==lg)
                {
                    sv[nu].push_back(q);
                    sv[q].push_back(nu);
                    lg=lg2, se.erase(itl);
                }
            }
            if(itr!=se.end())
            {
                int lg2=(*itr).first, rg2=(*itr).second.first, nu=(*itr).second.second;
                if(lg2==rg)
                {
                    sv[nu].push_back(q);
                    sv[q].push_back(nu);
                    rg=rg2, se.erase(itr);
                }
            }
            se[lg]=make_pair(rg, q), q++;
        }
        else
        {
            auto it=se.upper_bound(lg);
            it--;
            int lg2=(*it).first, rg2=(*it).second.first, nu=(*it).second.second;
            se.erase(it);
            if(lg2<lg) se[lg2]=make_pair(lg, nu);
            if(rg2>rg) se[rg]=make_pair(rg2, nu);
        }
    }
    int cq=0;
    for(int a=0; a<q; a++)
    {
        if(us[a]==0)
        {
            dfs(a), cq++;
        }
    }
    cout<<cq;
}
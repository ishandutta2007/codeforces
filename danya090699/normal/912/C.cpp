#include <bits/stdc++.h>
using namespace std;
const int inf=2e9;
int de(int a, int b)
{
    int re=a/b;
    if(a%b>0) re++;
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, bounty, increase, damage;
    cin>>n>>m>>bounty>>increase>>damage;
    int ma[n], add[n], us[n], yk=0, q=0;
    set <pair <int, int> > se;
    pair <int, pair <int, int> > sp[n+m];
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d%d%d", &ma[a], &x, &add[a]);
        sp[a].first=0, sp[a].second.first=a+1, sp[a].second.second=x;
        us[a]=-1;
        if(ma[a]<=damage) q++;
    }
    for(int a=n; a<m+n; a++) scanf("%d%d%d", &sp[a].first, &sp[a].second.first, &sp[a].second.second);
    sort(sp, sp+n+m);
        vector <pair <int, int> > ve;
        while(yk<n+m or se.size())
        {
            int cu=inf;
            if(yk<n+m) cu=sp[yk].first;
            if(se.size()) cu=min(cu, (*se.begin()).first);
            while(yk<n+m)
            {
                if(sp[yk].first==cu)
                {
                    int nu=sp[yk].second.first-1, he=sp[yk].second.second;
                    if(ma[nu]>damage)
                    {
                        if(us[nu]!=-1)
                        {
                            se.erase(make_pair(us[nu], nu)), q--;
                        }
                        if(add[nu]==0)
                        {
                            if(he<=damage) us[nu]=1;
                            else us[nu]=-1;
                        }
                        else
                        {
                            int t=cu+de(damage+1-min(he, damage+1), add[nu]);
                            us[nu]=t;
                            se.insert(make_pair(us[nu], nu));
                        }
                        if(us[nu]!=-1) q++;
                    }
                    yk++;
                }
                else break;
            }
            while(se.size())
            {
                if((*se.begin()).first==cu)
                {
                    int nu=(*se.begin()).second;
                    us[nu]=-1, q--;
                    se.erase(se.begin());
                }
                else break;
            }
            ve.push_back(make_pair(cu, q));
        }
        if(increase==0)
        {
            long long an=0;
            for(int a=0; a<ve.size(); a++)
            {
                int x=1ll*ve[a].second*bounty;
                if(x>an) an=x;
            }
            cout<<an;
        }
        else
        {
            if(ve.back().second>0) cout<<-1;
            else
            {
                long long an=0;
                for(int a=0; a<ve.size()-1; a++)
                {
                    int q=ve[a].second, t=ve[a+1].first-1;
                    long long x=1ll*q*(bounty+1ll*t*increase);
                    if(an<x) an=x;
                }
                cout<<an;
            }
        }
}
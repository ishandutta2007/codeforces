#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=4e7, inf=2e18;
bitset <sz> er;
vector <int> di;
int po(int x, int y, int mod)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(re*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    for(int a=2; a<sz; a++)
    {
        if(er[a]==0)
        {
            di.push_back(a);
            for(int b=a*a; b<sz; b+=a) er[b]=1;
        }
    }
    int t;
    cin>>t;
    bool an[t];
    map <int, vector <pair <int, int> > > ma;
    for(int a=0; a<t; a++)
    {
        int n, k;
        cin>>n>>k;
        ma[k].push_back(make_pair(n, a));
    }
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        int k=(*it).first;
        vector <pair <int, int> > &sp=(*it).second;
        vector <int> d;
        for(int a=0; a<di.size(); a++)
        {
            if(di[a]*di[a]>k) break;
            if(k%di[a]==0)
            {
                d.push_back(di[a]);
                while(k%di[a]==0) k/=di[a];
            }
        }
        if(k>1) d.push_back(k);
        if(d.size()==0)
        {
            for(int a=0; a<sp.size(); a++) an[sp[a].second]=0;
        }
        else if(d.size()==1)
        {
            for(int a=0; a<sp.size(); a++)
            {
                if(sp[a].first%d[0]==0) an[sp[a].second]=1;
                else an[sp[a].second]=0;
            }
        }
        else if(d.size()==2)
        {
            int d1=d[0], d2=d[1];
            for(int a=0; a<sp.size(); a++)
            {
                int n=sp[a].first, nu=sp[a].second;
                int x=((n%d1)*po(d2%d1, d1-2, d1))%d1;
                if(x*d2<=n) an[nu]=1;
                else an[nu]=0;
            }
        }
        else
        {
            int d1=d[0];
            int be[d1];
            for(int a=0; a<d1; a++) be[a]=inf;
            be[0]=0;
            set <pair <int, int> > se;
            se.insert(make_pair(0, 0));
            while(se.size())
            {
                int v=(*se.begin()).second;
                se.erase(se.begin());
                for(int a=1; a<d.size(); a++)
                {
                    int ne=(v+d[a])%d1, va=be[v]+d[a];
                    if(be[ne]>va)
                    {
                        se.erase(make_pair(be[ne], ne));
                        be[ne]=va;
                        se.insert(make_pair(be[ne], ne));
                    }
                }
            }

            for(int a=0; a<sp.size(); a++)
            {
                int n=sp[a].first, nu=sp[a].second;
                if(n>=be[n%d1]) an[nu]=1;
                else an[nu]=0;
            }
        }
    }
    for(int a=0; a<t; a++)
    {
        if(an[a]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
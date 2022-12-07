#include <bits/stdc++.h>
#define int long long
using namespace std;
const int bl=300, sz=1e5+10;
int zap[sz][2];
bool comp(int a, int b){return zap[a][0]<zap[b][0];}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    set <int> se;
    int ty[n], ar[n+1];
    ar[0]=0;
    se.insert(0);
    for(int a=0; a<n; a++) scanf("%lld", &ty[a]);
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        if(ty[a]==2) x=-x;
        ar[a+1]=ar[a]+x;
        se.insert(ar[a+1]);
    }
    vector <int> ch;
    for(set <int>::iterator it=se.begin(); it!=se.end(); it++) ch.push_back(*it);
    int m=ch.size();
    int su[n+1], q[m], pr[n+1], prq[n+1];
    vector <pair <int, int> > sp[m];
    for(int a=0; a<m; a++) q[a]=0;
    for(int a=0; a<=n; a++) su[a]=0;
    for(int a=0; a<=n; a++)
    {
        int nu=a/bl;
        ar[a]=lower_bound(ch.begin(), ch.end(), ar[a])-ch.begin();
        pr[a]=-1;
        if(se.find(ch[ar[a]]-k)!=se.end())
        {
            pr[a]=lower_bound(ch.begin(), ch.end(), ch[ar[a]]-k)-ch.begin();
            prq[a]=q[pr[a]];
            vector <pair <int, int> > &ve=sp[pr[a]];
            if(ve.size()>0)
            {
                if(ve.back().first==nu) ve.back().second++;
                else ve.push_back(make_pair(nu, 1));
            }
            else ve.push_back(make_pair(nu, 1));
        }
        else
        {
            pr[a]=-1, prq[a]=0;
        }
        su[nu]+=prq[a];
        q[ar[a]]++;
    }
    for(int a=0; a<m; a++) q[a]=0;
    int qq;
    cin>>qq;
    int p[qq], yk=0, an[qq];
    for(int a=0; a<qq; a++)
    {
        scanf("%lld%lld", &zap[a][0], &zap[a][1]);
        zap[a][0]--, p[a]=a;
    }
    sort(p, p+qq, comp);
    for(int a=0; a<n; a++)
    {
        while(yk<qq)
        {
            int i=p[yk];
            if(zap[i][0]==a)
            {
                int r=zap[i][1];
                an[i]=0;
                for(int b=0; b<=n; b+=bl)
                {
                    int rg=min(b+bl-1, n);
                    if(a+1<=b and r>=rg) an[i]+=su[b/bl];
                    else
                    {
                        for(int c=max(a+1, b); c<=min(r, rg); c++)
                        {
                            an[i]+=prq[c];
                            if(pr[c]!=-1) an[i]-=q[pr[c]];
                        }
                    }
                }
                yk++;
            }
            else break;
        }
        q[ar[a]]++;
        for(int b=0; b<sp[ar[a]].size(); b++)
        {
            int nu=sp[ar[a]][b].first, qu=sp[ar[a]][b].second;
            su[nu]-=qu;
        }
    }
    for(int a=0; a<qq; a++) printf("%lld\n", an[a]);
}
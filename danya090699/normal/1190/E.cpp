#include <bits/stdc++.h>
using namespace std;
const double eps=1e-8, PI=atan2(0, -1), inf=1e9;
const int sz=2e5+10;
int n, m, ok;
vector <int> sv[sz], st;
void dfs(int v)
{
    if(v<n)
    {
        int q=min(m, int(st.size()));
        if(st[st.size()-min(m, int(st.size()))]>=v+n) ok=1;
    }
    st.push_back(v);
    for(int a=0; a<sv[v].size(); a++) dfs(sv[v][a]);
    st.pop_back();
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    int ar[n][2];
    double lg=eps, rg=inf;
    for(int a=0; a<n; a++)
    {
        scanf("%d%d", &ar[a][0], &ar[a][1]);
        if(ar[a][0]==0 and ar[a][1]==0)
        {
            cout<<0;
            return 0;
        }
        rg=min(rg, sqrt(1ll*ar[a][0]*ar[a][0]+1ll*ar[a][1]*ar[a][1]));
    }
    rg-=eps;
    for(int i=0; i<40; i++)
    {
        double mid=(lg+rg)/2;
        vector <pair <double, double> > sp;
        for(int a=0; a<n; a++)
        {
            double x=ar[a][0], y=ar[a][1];

            double g=sqrt(x*x+y*y), l=sqrt(x*x+y*y-mid*mid);

            double k2=(l*l)/(g*g), x2=x-x*k2, y2=y-y*k2;

            double k3=(l*mid)/(g*g), xl=x2+y*k3, yl=y2-x*k3, xr=x2-y*k3, yr=y2+x*k3;

            double L=atan2(yl-y, xl-x), R=atan2(y-yr, x-xr);

            if(R<L) R+=2*PI;

            sp.push_back({L, R});
            sp.push_back({L+2*PI, R+2*PI});
        }
        sort(sp.begin(), sp.end());
        double mir=inf;
        int yk=sp.size()-1;
        for(int a=sp.size()-1; a>=0; a--)
        {
            while(sp[yk].first>mir) yk--;
            if(yk==a) sv[2*n].push_back(a);
            else sv[yk].push_back(a);
            mir=min(mir, sp[a].second);
        }
        ok=0;
        dfs(2*n);
        if(ok) lg=mid;
        else rg=mid;

        for(int a=0; a<=2*n; a++) sv[a].clear();
    }
    cout<<fixed<<setprecision(10)<<lg;
}
#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    pair <int, pair <int, int> > ve[n*m];
    int an[n][m], yk=0, q=0, su=0, sux=0, sqx=0, suy=0, sqy=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            int x;
            scanf("%d", &x);
            ve[a*m+b].first=x, ve[a*m+b].second.first=a, ve[a*m+b].second.second=b;
        }
    }
    sort(ve, ve+n*m);
    while(yk<n*m)
    {
        int st=yk;
        while(yk<n*m)
        {
            if(ve[yk].first==ve[st].first)
            {
                int x=ve[yk].second.first, y=ve[yk].second.second;
                int xadd=(1ll*q*x*x+sqx)%mod-(2ll*sux*x)%mod;
                if(xadd<0) xadd+=mod;
                int yadd=(1ll*q*y*y+sqy)%mod-(2ll*suy*y)%mod;
                if(yadd<0) yadd+=mod;
                an[x][y]=(1ll*(0ll+su+xadd+yadd)*po(q, mod-2))%mod;
                yk++;
            }
            else break;
        }
        for(st; st<yk; st++)
        {
            int x=ve[st].second.first, y=ve[st].second.second;
            q++, sux=(sux+x)%mod, sqx=(sqx+x*x)%mod, suy=(suy+y)%mod, sqy=(sqy+y*y)%mod;
            su=(su+an[x][y])%mod;
        }
    }
    int r, c;
    cin>>r>>c;
    r--, c--;
    cout<<an[r][c];
}
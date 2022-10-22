#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

int mk[MAXN],dp[MAXN][2][2];

void build(int p,int l,int r)
{
    if(l==r-1)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                if(i || j)
                    dp[p][i][j]=-1e6;
        if(mk[l] && mk[r])
            dp[p][1][1]=1;
        else if(mk[l] || mk[r])
            dp[p][1][0]=dp[p][0][1]=1;
        return;
    }
    int mid=(l+r)>>1;

    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(i || j)
                dp[p][i][j]=-1e6;
    for(int i1=0;i1<2;i1++)
        for(int j1=0;j1<2;j1++)
            for(int i2=0;i2<2;i2++)
                for(int j2=0;j2<2;j2++)
                {
                    int base=dp[p<<1][i1][j1]+dp[(p<<1)+1][i2][j2];
                    for(int p1=0;p1<2;p1++)
                    {
                        int v1,vv1;
                        if(!p1)
                            v1=i1;
                        else
                            v1=i2;
                        vv1=i1+i2-v1;
                        for(int p2=0;p2<2;p2++)
                        {
                            int v2;
                            if(!p2)
                                v2=j1;
                            else
                                v2=j2;
                            for(int p3=0;p3<2;p3++)
                            {
                                int v3;
                                if(!p3)
                                    v3=v2;
                                else
                                    v3=vv1;
                                dp[p][v1][v3]=max(dp[p][v1][v3],base+(i1|i2)+(j1|j2)+(v2|vv1));
                            }
                        }
                    }
                }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,a;
    cin >> n >> k;
    for(int i=0;i<k;i++)
    {
        cin >> a;
        a--;
        mk[a]=1;
    }

    build(1,0,(1<<n)-1);

    int res=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            res=max(res,dp[1][i][j]);
    if(k)
        res++;
    db(res)

    return 0;
}
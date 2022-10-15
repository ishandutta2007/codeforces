#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll; typedef long double ld;

const int N=100+17;
const int S=1000+17;

const ld INF=1e10;

ld drunk[N];

struct kek
{
        int a;
        int p;
};

int n;
ld con,dur;

ld dp[N][S];

inline ld calc(ld dormit,int cnt,int s)
{
        return (dormit)+dp[cnt][s]/(dormit*con+1.0)+10.0*(ld)cnt;
}


bool operator < (kek f,kek s)
{
        return f.a>s.a;
}

kek v[N];

inline void clr_dp()
{
        for(int i=0;i<N;i++)
        {
                for(int j=0;j<S;j++)
                {
                        dp[i][j]=INF;
                }
        }
}

inline ld gt_min(int cnt,int s)
{
        /// Case1 :

        ld lo=0,hi=INF,mid,rs;
        for(int i=1;i<=100;i++)
        {
                mid=(lo+hi)*0.5;
                if(calc(mid,cnt,s)<=calc(mid-0.0001,cnt,s))
                {
                        rs=mid;
                        lo=mid;
                }
                else
                {
                        hi=mid;
                }
        }
        return calc(rs,cnt,s);

        /// Case2 :

        /**int lo=0,hi=1e9,mid,rs;
        while(lo<=hi)
        {
                mid=(lo+hi)>>1;
                if(calc(mid,cnt,s)<=calc(mid-1,cnt,s))
                {
                        rs=mid;
                        lo=mid+1;
                }
                else
                {
                        hi=mid-1;
                }
        }
        return calc(rs,cnt,s);**/
}

inline int gt()
{
        for(int s=10*n;s>=0;s--)
        {
                for(int cnt=n;cnt>=0;cnt--)
                {
                        if(dp[cnt][s]==INF) continue;
                        if(gt_min(cnt,s)<=dur || dp[cnt][s]+10.0*(ld)cnt<=dur)
                        {
                                return s;
                        }
                }
        }
        return 0;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ///freopen("input","r",stdin); freopen("output","w",stdout);
        drunk[0]=1.0;
        for(int i=1;i<N;i++) drunk[i]=drunk[i-1]*1.111111111111;
        int tests;
        cin>>tests;
        for(int tc=1;tc<=tests;tc++)
        {
                cin>>n;
                cin>>con>>dur;
                for(int i=1;i<=n;i++)
                {
                        cin>>v[i].a>>v[i].p;
                }
                sort(v+1,v+n+1);
                clr_dp();
                dp[0][0]=0;
                for(int i=1;i<=n;i++)
                {
                        for(int cnt=n;cnt>=0;cnt--)
                        {
                                for(int s=10*n;s>=0;s--)
                                {
                                        dp[cnt+1][s+v[i].p]=min(dp[cnt+1][s+v[i].p],dp[cnt][s]+(ld)v[i].a*drunk[cnt+1]);
                                }
                        }
                }
                cout<<gt()<<"\n";
              ///  return 0;
        }
}
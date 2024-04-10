#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=5000+5;

int n,d,cnt;

ll dp[N][N]; /// dp[i][chosen]
ll v[N];

int deq[N][N];
int st[N];
int dr[N];

/**
struct info
{
    int id;
    ll x;
};

bool operator < (info a,info b)
{
    if(a.x==b.x)
    {
        return a.id<b.id;
    }
    return a.x>b.x;
}
set<info>best[N];
**/
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0;i<N;i++)
    {
        st[i]=dr[i]+1;
    }
    cin>>n>>d>>cnt;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            dp[i][j]=-(1LL<<60);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int ch=cnt;ch>=2;ch--)
        {
           // for(int j=i-1;j>=1 && i-j<=d;j--)
           // {
           //     dp[i][ch]=max(dp[i][ch],v[i]+dp[j][ch-1]);
           // }
           if(st[ch-1]<=dr[ch-1])
           {
                int id=deq[ch-1][st[ch-1]];
                dp[i][ch]=dp[ id ] [ch-1]+v[i];
                while(st[ch]<=dr[ch] && dp[i][ch]>=dp[deq[ch][dr[ch]]][ch])
                {
                    dr[ch]--;
                }
                if(st[ch]<=dr[ch] && deq[ch][st[ch]]<=i-d)
                {
                    st[ch]++;
                }
                deq[ch][++dr[ch]]=i;
            }
        }
                int ch=1;
        if(i<=d)
        {
            dp[i][ch]=v[i];
            while(st[ch]<=dr[ch] && dp[i][ch]>=dp[deq[ch][dr[ch]]][ch])
            {
                dr[ch]--;
            }
        }

        if(st[ch]<=dr[ch] && deq[ch][st[ch]]<=i-d)
                {
                    st[ch]++;
                }
                deq[ch][++dr[ch]]=i;
    }
    ll ans=-(1LL<<60);
    for(int i=n;i>=n-d+1;i--)
    {
        ans=max(ans,dp[i][cnt]);
    }
    if(ans<0)
    {
        ans=-1;
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/
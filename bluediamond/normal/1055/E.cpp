#include <bits/stdc++.h>

using namespace std;

const int N=1500+5;

int n,s,m,k;
int v[N];

struct interval
{
    int st;
    int dr;
};

bool cmp(interval a,interval b)
{
    if(a.dr==b.dr)
    {
        return a.st<b.st;
    }
    else
    {
        return a.dr<b.dr;
    }
}

interval a[N];

int prefix[N];
int dp[N][N];
int dp_prefix[N][N];

int id[N];
int ncoinc[N];

inline int get_max(int x)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            dp[i][j]=0;
            dp_prefix[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+(v[i]<=x);
     //   cout<<prefix[i]-prefix[i-1]<<" ";
    }
   // cout<<"\n";
    int ans=0;
    for(int i=1;i<=s;i++)
    {
        dp[1][i]=prefix[a[i].dr]-prefix[a[i].st-1];
        dp_prefix[1][i]=max(dp_prefix[1][i-1],dp[1][i]);
        ans=max(ans,dp[1][i]);
    }
    for(int take=2;take<=m;take++)
    {
        for(int i=1;i<=s;i++)
        {
            if(id[i]!=-1)
            {
                int st=a[id[i]].dr+1;
                int dr=a[i].dr;
                dp[take][i]=max(dp[take][i],dp[take-1][id[i]]+prefix[dr]-prefix[st-1]);
            }
            if(ncoinc[i]!=-1)
            {
                dp[take][i]=max(dp[take][i],dp_prefix[take-1][ncoinc[i]]+prefix[a[i].dr]-prefix[a[i].st-1]);
            }
            dp_prefix[take][i]=max(dp_prefix[take][i-1],dp[take][i]);
            ans=max(ans,dp[take][i]);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ///  freopen("input","r",stdin);
  ///  freopen("output","w",stdout);
    cin>>n>>s>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=s;i++)
    {
        cin>>a[i].st>>a[i].dr;
        id[i]=-1;
    }
    sort(a+1,a+s+1,cmp);
    for(int i=1;i<=s;i++)
    {
        int mi=(1<<30);
        for(int j=1;j<i;j++)
        {
            if(a[j].dr>=a[i].st)
            {
                mi=min(mi,a[j].st);
            }
        }
        for(int j=1;j<i;j++)
        {
            if(a[j].dr>=a[i].st && mi==a[j].st)
            {
                id[i]=j;
            }
        }
    }
    for(int i=1;i<=s;i++)
    {
        ncoinc[i]=-1;
        for(int j=i-1;j>=1;j--)
        {
            if(a[j].dr<a[i].st)
            {
                ncoinc[i]=j;
                break;
            }
        }
    }
    int r=0,pas=(1<<30);
    while(pas)
    {
        if(get_max(r+pas)<k)
        {
            r+=pas;
        }
        pas>>=1;
    }
    if(r==(1LL<<31)-1)
    {
        cout<<"-1\n";
        return 0;
    }
    r++;
    cout<<r<<"\n";
    return 0;
}
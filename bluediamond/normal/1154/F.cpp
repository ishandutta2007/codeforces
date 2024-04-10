#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;
const int K=2000+7;

int n,m,k;
int v[N];
int kol[K];
int dp[K];
int p[K];

int get(int l,int r)
{
        return p[r]-p[l-1];
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
        }
        sort(v+1,v+n+1);
        n=k;
        for(int i=1;i<=n;i++)
        {
                kol[i]=-1;
        }
        for(int j=1;j<=m;j++)
        {
                int a,b;
                cin>>a>>b;
                if(a<=n)
                {
                        kol[a]=max(kol[a],b);
                }
        }
        for(int i=1;i<=n;i++)
        {
                p[i]=p[i-1]+v[i];
        }
        for(int i=1;i<=n;i++)
        {
                if(kol[i]==-1) continue;
                kol[i]=i-kol[i];
        }
        for(int i=1;i<=n;i++)
        {
                dp[i]=(1<<30);
                for(int j=1;j<=i;j++)
                {
                        if(kol[j]==-1) continue;
                        int cur=dp[i-j]+get(i-kol[j]+1,i);
                        dp[i]=min(dp[i],cur);
                }
                dp[i]=min(dp[i],dp[i-1]+v[i]);
        }
        cout<<dp[n]<<"\n";
        return 0;
}
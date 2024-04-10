#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    s="$"+s;
    int l=0,r=n+1;
    while(l<r-1)
    {
        int m=(l+r)/2;
        vector nxt(n+2,vector(k,-1));
        array<int,17> cnt;
        cnt.fill(0);
        int c=0;
        auto add=[&](int i,int d)
        {
            if(s[i]!='?')
            {
                cnt[s[i]-'a']+=d;
                c+=d;
            }
        };
        for(int i=n;i>=n-m+2;i--) add(i,1);
        for(int i=n-m+1;i>=1;i--)
        {
            add(i,1);
            for(int j=0;j<k;j++)
            {
                nxt[i][j]=nxt[i+1][j];
                if(cnt[j]==c) nxt[i][j]=i;
            }
            add(i+m-1,-1);
        }
        vector<int> dp((1<<k),-1);
        dp[0]=1;
        for(int mask=1;mask<(1<<k);mask++)
        {
            for(int j=0;j<k;j++)
            {
                if((mask&(1<<j))==0) continue;
                int p=dp[mask^(1<<j)];
                if(p==-1||nxt[p][j]==-1) continue;
                if(dp[mask]==-1||nxt[p][j]+m<dp[mask]) dp[mask]=nxt[p][j]+m;
            }
        }
        if(dp[(1<<k)-1]!=-1) l=m;
        else r=m;
    }
    cout << l << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> s(n,0);
    vector<vector<int>> cnt(n); //count of d
    vector<vector<int>> up(n); //count of d+1 before first pos of d
    vector<int> e(n,0);
    vector<int> dip(n,0);
    for(int i=0;i<n;i++)
    {
        string t;
        cin >> t;
        int m=t.size();
        s[i]=m;
        cnt[i].assign(2*m+1,0);
        up[i].assign(2*m+1,0);
        int d=0;
        for(int j=0;j<m;j++)
        {
            if(t[j]=='(') d++;
            else d--;
            if((++cnt[i][d+m])==1) up[i][d+m]=cnt[i][d+1+m];
            dip[i]=min(dip[i],d);
        }
        e[i]=d;
    }
    vector<int> dp((1<<n),-1);
    dp[0]=0;
    vector<int> sum((1<<n),0);
    for(int m=1;m<(1<<n);m++) for(int i=0;i<n;i++) if(m&(1<<i)) sum[m]=sum[m^(1<<i)]+e[i];
    int res=0;
    for(int m=0;m<(1<<n);m++)
    {
        if(dp[m]==-1) continue;
        res=max(res,dp[m]);
        for(int i=0;i<n;i++)
        {
            if(m&(1<<i)) continue;
            if(sum[m]+dip[i]>=0) dp[m^(1<<i)]=max(dp[m^(1<<i)],dp[m]+(-sum[m]>=-s[i]?cnt[i][-sum[m]+s[i]]:0));
            else res=max(res,dp[m]+up[i][-sum[m]-1+s[i]]);
        }
    }
    cout << res << "\n";
    return 0;
}
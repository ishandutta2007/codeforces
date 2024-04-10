#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+7;
int n, a[N], dp[N][2], l[N], r[N], par[N][2];

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        int t;
        cin>>t;
        while (t--)
        {
                cin>>n;
                string s;
                cin>>s;
                for (int i=1; i<=n; i++)
                {
                        char c=s[i-1];
                        if (c=='?') a[i]=-1;
                        else {
                                if (c=='B') a[i]=0;
                                else a[i]=1;
                        }
                        if (a[i]==-1) l[i]=0, r[i]=1;
                        else l[i]=a[i], r[i]=a[i];
                }
                dp[1][0]=dp[1][1]=(int) 1e9;
                for (int j=l[1]; j<=r[1]; j++)
                {
                        dp[1][j]=0;
                }
                for (int i=2; i<=n; i++)
                {
                        dp[i][0]=dp[i][1]=(int) 1e9;
                        for (int j=l[i]; j<=r[i]; j++)
                        {
                                for (int ant=0; ant<=1; ant++)
                                {
                                        dp[i][j]=min(dp[i][j], dp[i-1][ant]+(ant==j));
                                        if (dp[i-1][ant]+(ant==j)==dp[i][j])
                                        {
                                                par[i][j]=ant;
                                        }
                                }
                        }
                }
                int ind, i=n;
                if (dp[n][0]<dp[n][1]) ind=0;
                else ind=1;
                string sol;
                while (i>=1)
                {
                        if (ind==0) sol+="B";
                        else sol+="R";

                        ind=par[i][ind];
                        i--;
                }
                reverse(sol.begin(), sol.end());
                cout<<sol<<"\n";
                ///cout<<min(dp[n][0], dp[n][1])<<"\n";
        }


        return 0;
}
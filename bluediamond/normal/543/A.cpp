#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=500+7;
int n, m, b, mod, a[N], dp[N][N], dp2[N][N]; /// dp[last prog][lines written][bugs]

void addup(int &a, int b)
{
        a=(a+b)%mod;
}

int main()
{
        cin>>n>>m>>b>>mod;

        if (mod==1)
        {
                cout<<"0\n";
                return 0;
        }

        for (int i=1; i<=n; i++)
                cin>>a[i];


        dp[0][0]=1;

        for (int lp=1; lp<=n; lp++)
        {
                for (int lw=0; lw<=m; lw++)
                {
                        for (int bg=0; bg<=b; bg++)
                        {
                                addup(dp2[lw][bg], dp[lw][bg]);
                                if (lw>=1 && a[lp]<=bg)
                                {
                                        addup(dp2[lw][bg], dp2[lw-1][bg-a[lp]]);
                                }
                        }
                }

                for (int lw=0; lw<=m; lw++)
                {
                        for (int bg=0; bg<=b; bg++)
                        {
                                dp[lw][bg]=dp2[lw][bg];
                                dp2[lw][bg]=0;
                        }
                }
        }

        int sol=0;
        for (int bg=0; bg<=b; bg++)
        {
                addup(sol, dp[m][bg]);
        }
        cout<<sol<<"\n";


        return 0;
}
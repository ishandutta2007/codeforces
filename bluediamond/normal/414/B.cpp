#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=2000+7;
const int M=(int) 1e9+7;
int n;
int k;
int dp[N][N]; /// dp[len][x]

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin>>n>>k;
        for (int i=1;i<=n;i++)
                dp[1][i]=1;
        for (int l=2;l<=k;l++)
                for (int i=1;i<=n;i++)
                        for (int j=i;j<=n;j+=i)
                                dp[l][j]=(dp[l][j]+dp[l-1][i])%M;
        int sol=0;
        for (int i=1;i<=n;i++)
                sol=(sol+dp[k][i])%M;
        cout<<sol<<"\n";
}
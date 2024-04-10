#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=100;
    vector dp(N+1,vector(N+1,array<int,2>{0,0}));
    dp[0][0][0]=1;
    for(int n=1;n<=N;n++)
    {
        for(int o=0;o<=n;o++)
        {
            for(int c=0;c<=1;c++)
            {
                for(int t=0;t<=1;t++) //take t
                {
                    if(t==0&&n-o==0) continue;
                    if(t==1&&o==0) continue;
                    int nc=(c^t);
                    dp[n][o][c]|=(dp[n-1][o-t][nc^1^((o-t)&1)]==0);
                }
            }
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int o=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            o+=(a&1);
        }
        if(dp[n][o][0]==1) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}
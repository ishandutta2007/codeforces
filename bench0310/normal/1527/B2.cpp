#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=500;
    const int inf=(1<<30);
    int dp[N+1][N+1][2][2]; //two,one,mid,rev
    for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) for(int a=0;a<2;a++) for(int b=0;b<2;b++) dp[i][j][a][b]=inf;
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            for(int m=0;m<2;m++)
            {
                for(int r=1;r>=0;r--)
                {
                    int &now=dp[i][j][m][r];
                    if(i+j+m==0)
                    {
                        now=0;
                        continue;
                    }
                    if(i>0&&j+1<=N) now=min(now,1-dp[i-1][j+1][m][0]);
                    if(j>0) now=min(now,1-dp[i][j-1][m][0]);
                    if(m==1) now=min(now,1-dp[i][j][0][0]);
                    if(j>0&&r==0) now=min(now,-dp[i][j][m][1]);
                }
            }
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int one=0,two=0,mid=0;
        for(int i=0;i<=n-1-i;i++)
        {
            int a=(s[i]=='1');
            int b=(s[n-1-i]=='1');
            if(i==n-1-i) mid=(a==0);
            else if(a+b==0) two++;
            else if(a+b==1) one++;
        }
        int res=dp[two][one][mid][0];
        if(res<0) cout << "ALICE\n";
        else if(res>0) cout << "BOB\n";
        else cout << "DRAW\n";
    }
    return 0;
}
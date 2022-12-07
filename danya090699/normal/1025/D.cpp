#include <bits/stdc++.h>
using namespace std;
const int sz=702;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    bool sm[n][n];
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) sm[a][b]=(__gcd(ar[a], ar[b])>1);
    bool dp[n][n];
    for(int a=0; a<n; a++) dp[a][a]=1;
    for(int a=1; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            if(b-a>=0)
            {
                dp[b][b-a]=0;
                for(int c=b-a; c<b; c++) if(sm[b][c] and dp[c][b-a] and dp[c][b-1]) dp[b][b-a]=1;
            }
            if(b+a<n)
            {
                dp[b][b+a]=0;
                for(int c=b+1; c<=b+a; c++) if(sm[b][c] and dp[c][b+1] and dp[c][b+a]) dp[b][b+a]=1;
            }
        }
    }
    int ok=0;
    for(int a=0; a<n; a++) if(dp[a][0] and dp[a][n-1]) ok=1;
    if(ok) cout<<"Yes";
    else cout<<"No";
}
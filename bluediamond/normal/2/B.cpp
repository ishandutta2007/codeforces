#include <bits/stdc++.h>

using namespace std;

const int N=1000;
int n;
int v[N+5][N+5];
int p2[N+5][N+5];
int p5[N+5][N+5];
bool e0=0;
int dp2[N+5][N+5];
int dp5[N+5][N+5];
int dp[N+5][N+5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            dp2[i][j]=dp5[i][j]=(1<<30);
    dp2[0][1]=dp2[1][0]=0;
    dp5[0][1]=dp5[1][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            cin>>v[i][j];
            if(v[i][j]==0)
                e0=1;
            if(v[i][j]) {
                while(v[i][j]%2==0){v[i][j]/=2;p2[i][j]++;}
                while(v[i][j]%5==0){v[i][j]/=5;p5[i][j]++;}
            }
            dp2[i][j]=min(dp2[i-1][j],dp2[i][j-1])+p2[i][j];
            dp5[i][j]=min(dp5[i-1][j],dp5[i][j-1])+p5[i][j];
        }
    int ans=min(dp2[n][n],dp5[n][n]);
    if(ans>1 && e0==1) {
        cout<<"1\n";
        int r,c;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(v[i][j]==0) {
                    r=i;
                    c=j;
                }
        for(int i=1;i<r;i++)cout<<"D";
        for(int i=1;i<c;i++)cout<<"R";
        for(int i=1;i<=n-r;i++)cout<<"D";
        for(int i=1;i<=n-c;i++)cout<<"R";
        cout<<"\n";
        return 0;
    }
    if(dp2[n][n]<dp5[n][n])
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=dp2[i][j];
    else
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=dp5[i][j];
    cout<<ans<<"\n";
    string sl;
    int i=n,j=n;
    while(i>1 || j>1) {
        if(i==1) {
            j--;
            sl+="R";
            continue;
        }
        if(j==1) {
            i--;
            sl+="D";
            continue;
        }
        if(dp[i-1][j]<dp[i][j-1]) {
            i--;
            sl+="D";
        }
        else {
            j--;
            sl+="R";
        }
    }
    reverse(sl.begin(),sl.end());
    cout<<sl<<"\n";
    return 0;
}
/**

3
100 0 100
100 100 100
100 100 100

**/
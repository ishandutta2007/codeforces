#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>

using namespace std;


const int N=700+5;

int n;
int v[N];
bool ok[N][N];
bool dp[N][N][2][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>>n;

    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }

    if(n==2) {
        if(__gcd(v[1],v[2])!=1)  {
            cout<<"Yes\n";
        }
        else {
            cout<<"No\n";
        }
        return 0;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            ok[i][j]=(__gcd(v[i],v[j])!=1);
        }
    }

    v[1]=v[n+1]=1;

    for(int st=0;st<N;st++) {
        for(int dr=0;dr<st;dr++) {
            dp[st][dr][0][0]=1;
            dp[st][dr][0][1]=1;
            dp[st][dr][1][0]=1;
            dp[st][dr][1][1]=1;
        }
    }

    for(int i=1;i<=n;i++) {
        for(int a=0;a<2;a++) {
            for(int b=0;b<2;b++) {
                dp[i][i][a][b]=(__gcd(__gcd(v[i],v[i-a]),v[i+b])!=1);
            }
        }
    }

    for(int l=2;l<=n;l++) {
        for(int st=1;st+l-1<=n;st++) {
            int dr=st+l-1;
            for(int k=st;k<=dr;k++) {
                bool ok1=ok[k][st-1];
                bool ok2=ok[k][dr+1];
                dp[st][dr][ok1][ok2]|=((dp[st][k-1][0][1] | dp[st][k-1][1][1]) && (dp[k+1][dr][1][0] |dp[k+1][dr][1][1] ));
            }
        }
    }

    int ans=0;

    ans|=dp[1][n][0][0];
    ans|=dp[1][n][0][1];
    ans|=dp[1][n][1][0];
    ans|=dp[1][n][1][1];

    cout<<(ans ? "Yes" : "No")<<"\n";

    return 0;
}
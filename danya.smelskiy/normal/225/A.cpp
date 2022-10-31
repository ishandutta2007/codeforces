#include <bits/stdc++.h>
using namespace std;


int n,last;
bool dp[2][7];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>last;
    dp[0][last]=true;
    int x=0,y=1;
    for (int i=1;i<=n;++i) {
        swap(x,y);
        int xx,yy;
        cin>>xx>>yy;
        memset(dp[x],false,sizeof(dp[x]));
        for (int j=1;j<=6;++j) if (j!=xx && j!=yy && j!=7-xx && j!=7-yy) {
            bool t=false;
            for (int k=1;k<=6;++k)
            if (k!=j && dp[y][k]) {
                t=true;
                break;
            }
            if (t) dp[x][7-j]=true;
        }
    }
    int kol=0;
    for (int i=1;i<=6;++i)
        if (dp[x][i]) ++kol;
    if (kol==1) cout<<"YES";
    else cout<<"NO";
}
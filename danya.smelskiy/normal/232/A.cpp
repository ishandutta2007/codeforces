#include <bits/stdc++.h>
using namespace std;

int n;
int num;
bool dp[105][105];


main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=2;n;++i) {
        num=i;
        for (int j=1;j<i && n;++j) {
            int kol=0;
            for (int k=1;k<j;++k)
                if (dp[i][k] && dp[k][j]) ++kol;
            if (kol<=n) {
                n-=kol;
                dp[i][j]=dp[j][i]=true;
            }
        }
    }
    cout<<num<<endl;
    for (int i=1;i<=num;++i) {
        for (int j=1;j<=num;++j)
        if (dp[i][j] || dp[j][i]) cout<<"1";
        else cout<<"0";
        cout<<'\n';
    }
}
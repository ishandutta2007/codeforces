#include <bits/stdc++.h>
using namespace std;



int n;
int dp[100][100];
int q[100];
bool used[100];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0;i<10;++i)
        dp[i][1]=1;
    for (int i=1;i<=n;++i) {
        char c;
        int x;
        cin>>c>>x;
        for (int j=0;j<10;++j) {
            if (c=='|') {
                if (x&(1<<j))  {
                    dp[j][0]|=1;
                    dp[j][1]|=1;
                }
            } else if (c=='&') {
                if (x&(1<<j)) {
                    dp[j][0]&=1;
                    dp[j][1]&=1;
                } else {
                    dp[j][0]=dp[j][1]=0;
                }
            } else {
                if (x&(1<<j)) {
                    dp[j][0]^=1;
                    dp[j][1]^=1;
                }
            }
        }
    }
    used[2]=true;
    for (int i=0;i<10;++i) {
        q[2]|=(1<<i);
        if (dp[i][0]==0 && dp[i][1]==1) continue;
        if (dp[i][0]==1 && dp[i][1]==1) {
            used[1]=true;
            q[1]|=(1<<i);
        } else if (dp[i][0]==0 && dp[i][1]==0){
            q[2]^=(1<<i);
        } else {
            used[3]=true;
            q[3]|=(1<<i);
        }
    }
    int res=0;
    for (int i=1;i<=3;++i)
        if (used[i]) ++res;
    cout<<res<<'\n';
    if (used[1]) cout<<"| "<<q[1]<<'\n';
    if (used[2]) cout<<"& "<<q[2]<<'\n';
    if (used[3]) cout<<"^ "<<q[3]<<'\n';
}
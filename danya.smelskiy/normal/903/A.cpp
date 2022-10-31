#include <bits/stdc++.h>
using namespace std;

bool dp[105];
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    dp[0]=true;
    for (int i=1;i<=100;++i) {
        if (i>=3) dp[i]|=dp[i-3];
        if (i>=7) dp[i]|=dp[i-7];
    }
    cin>>n;
    while (n--) {
        int x;
        cin>>x;
        cout<<(dp[x] ? "YES" : "NO")<<'\n';
    }
}
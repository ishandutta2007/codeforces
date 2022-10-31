#include <bits/stdc++.h>
using namespace std;

int n,kol,kol2;
string s;
int dp[1005];

int main(){
    ///
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for (int i=0;i<n;++i) {
        int kol=1;
        int kol2=1;
        for (int j=i;j<s.size();++j)
            if (s[j]=='R') break; else if (s[j]=='L') ++kol;
        for (int j=i-1;j>=0;--j)
            if (s[j]=='L') break; else if (s[j]=='R') ++kol2;
        dp[i]=max(dp[i],kol);
        dp[i]=max(dp[i],kol2);
    }
    for (int i=0;i<n;++i)
        cout<<dp[i]<<" ";
}
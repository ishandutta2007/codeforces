#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
string s;
long long a[1005];
long long b[1005];
long long pref1[1005];
long long pref2[1005];
long long dp[1005][5];
bool used[1005][5];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>x>>y;
    for (int i=1;i<=n;++i){
        cin>>s;
        for (int j=1;j<=m;++j)
            if (s[j-1]=='#') ++a[j];
            else ++b[j];
    }
    for (int i=1;i<=m;++i){
        pref1[i]=pref1[i-1]+a[i];
        pref2[i]=pref2[i-1]+b[i];
    }
    used[0][1]=true;
    used[0][2]=true;
    for (int i=x;i<=m;++i){
        for (int j=x;j<=y;++j){
                if (i-j<0) break;
            if (used[i-j][1]==true) {
                if (used[i][2]==false) {
                    used[i][2]=true;
                    dp[i][2]=dp[i-j][1]+pref2[i]-pref2[i-j];
                } else {
                    dp[i][2]=min(dp[i][2],dp[i-j][1]+pref2[i]-pref2[i-j]);
                }
            }
            if (used[i-j][2]==true) {
                if (used[i][1]==false) {
                    used[i][1]=true;
                    dp[i][1]=dp[i-j][2]+pref1[i]-pref1[i-j];
                } else {
                    dp[i][1]=min(dp[i][1],dp[i-j][2]+pref1[i]-pref1[i-j]);
                }
            }
        }
    }
    cout<<min(dp[m][1],dp[m][2]);
}
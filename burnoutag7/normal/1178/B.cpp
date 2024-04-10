#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
ll dp[1000005][3];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    for(int i=1;i<s.size();i++){
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][1];
        dp[i][2]=dp[i-1][2];
        if(s[i]=='v'&&s[i-1]=='v'){
            dp[i][0]++;
            dp[i][2]+=dp[i][1];
        }
        if(s[i]=='o'){
            dp[i][1]+=dp[i][0];
        }
    }
    cout<<dp[s.size()-1][2]<<endl;

    return 0;
}
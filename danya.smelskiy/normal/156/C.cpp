#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
long long dp[200][2700];
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    dp[0][0]=1;
    for (int i=1;i<=100;++i) {
        long long sum=0;
        for (int j=0;j<=i*25;++j) {
            sum=(sum+dp[i-1][j])%md;
            if (j>25) sum=(sum-dp[i-1][j-26]+md)%md;
            dp[i][j]=sum;
        }
    }
    cin>>n;
    for (int i=1;i<=n;++i) {
        int sum=0;
        string s;
        cin>>s;
        for (int j=0;j<s.size();++j)
            sum+=s[j]-'a';
        cout<<(dp[(int)s.size()][sum]-1+md)%md<<'\n';
    }
}
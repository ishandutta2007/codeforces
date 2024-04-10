#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
const int maxk = 10 + 2;
const int mod = 1e8;
int n1,n2,k1,k2;
int dp[maxn][maxn][maxk][maxk];
int calc(int num1,int num2,int last1,int last2){
    if (dp[num1][num2][last1][last2] != -1){
        return dp[num1][num2][last1][last2];
    }
    int ans = 0;
    if (last1 > num1)ans = 0;
    else if (last2 > num2)ans = 0;
    else if (num1 == 0) {
        //2 only
        if (num2 == last2)
            ans = 1;
        else
            ans = 0;
    }else if (num2 == 0){
        //1 only
        if (num1 == last1)
            ans = 1;
        else
            ans = 0;
    }else if (last1 == 0){
            //2 last
            int top = min(num1,k1);
            for (int i=1;i<=top;i++){
                (ans += calc(num1,num2 - last2,i,0)) %= mod;
            }
    }else if (last2 == 0){
        //1 last
        int top = min(num2,k2);
        for (int i=1;i<=top;i++){
            (ans += calc(num1 - last1,num2,0,i)) %= mod;
        }
    }
    return dp[num1][num2][last1][last2] = ans;
}
int main(){
    scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
    memset(dp,-1,sizeof dp);
    int ans = 0;
    for (int i=1;i<=k1;i++){
        (ans += calc(n1,n2,i,0)) %= mod;
    }
    //cout<<ans<<endl;
    for (int i=1;i<=k2;i++){
        (ans += calc(n1,n2,0,i)) %= mod;
    }
    cout<<ans<<endl;
    return 0;
}
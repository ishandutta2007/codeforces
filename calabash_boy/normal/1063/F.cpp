#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ULL;
const int Base = 137;
const int Mod1 = 2000029;
int maxL1[Mod1 + 1];
int Hash1[maxn];
char s[maxn];
int n;
bool dp[2][maxn];
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    memset(dp,1,sizeof dp);
    maxL1[0]= n + 1;
    int now = 0;
    int ans = 1;
    for (int len = 1;len <=1000;len ++,now ^= 1){
        for (int l = 1;l + len - 1 <= n;l ++){
            int r = l + len - 1;
            if (max(maxL1[Hash1[l]],maxL1[Hash1[l+1]]) >r){
                dp[now][l] = true;
                ans = len;
            }else{
                dp[now][l] = false;
            }
        }
        if (ans == len-1){
            cout<<ans<<endl;
            return 0;
        }
        memset(maxL1,0,sizeof maxL1);
        for (int l = 1;l + len - 1 <= n;l ++){
            Hash1[l] = (Hash1[l+1] * Base + s[l]) % Mod1;
            if (dp[now][l]){
                maxL1[Hash1[l]] = l;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=5002;
int arr[MN];
int dp[MN];
int cnt[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n+1;i++){
            if(i<=n)cin>>arr[i];
            dp[i]=-1;
            int macnt=0;
            for(int j=1;j<=n;j++)cnt[j]=0;
            for(int j=i-1;j>=0;j--){
                if(i%2!=j%2&&(arr[i]==arr[j]||j==0||i==n+1)&&macnt<=(i-j-1)/2&&dp[j]!=-1){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                cnt[arr[j]]++;
                macnt=max(macnt,cnt[arr[j]]);
            }
        }
        printf("%d\n",dp[n+1]-1);
    }
    return 0;
}
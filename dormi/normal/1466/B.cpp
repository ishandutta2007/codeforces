#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e5+1;
int dp[MN][2];
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    arr[0]=-10;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            for(int j=0;j<2;j++){
                dp[i][j]=0;
                for(int k=0;k<2;k++){
                    if(arr[i-1]+k<=arr[i]+j){
                        dp[i][j]=max(dp[i][j],dp[i-1][k]+(arr[i-1]+k<arr[i]+j));
                    }
                }
            }
        }
        printf("%d\n",max(dp[n][0],dp[n][1]));
    }
    return 0;
}
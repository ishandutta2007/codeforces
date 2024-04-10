#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli dp[51][(int)2e4+1];
lli pre[51][(int)2e4+1];
lli suf[51][(int)2e4+1];
lli arr[2][(int)2e4+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int j=1;j<=m;j++){
        cin>>arr[0][j];
        arr[0][j]+=arr[0][j-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i!=n) {
                cin >> arr[1][j];
                arr[1][j] += arr[1][j - 1];
            }
            else{
                arr[1][j]=0;
            }
        }
        for(int j=k;j<=m;j++){
            dp[i][j]=max(pre[i-1][max(0,j-k)],(j+k<=m?suf[i-1][j+k]:0))+arr[1][j]-arr[1][max(0,j-k)]+arr[0][j]-arr[0][max(0,j-k)];
            for(int l=max(0,j-k+1);l<=j;l++){
                dp[i][j]=max(dp[i][j],pre[i-1][l]+arr[0][j]-arr[0][l]+arr[1][j]-arr[1][max(0,j-k)]);
            }
            for(int l=j+1;l<=min(m,j+k);l++){
                dp[i][j]=max(dp[i][j],suf[i-1][l]+arr[0][max(0,l-k)]-arr[0][max(0,j-k)]+arr[1][j]-arr[1][max(0,j-k)]);
            }
            pre[i][j]=max(pre[i][j-1],dp[i][j]);
        }
        suf[i][m]=dp[i][m];
        for(int j=m-1;j>=0;j--){
            suf[i][j]=max(suf[i][j+1],dp[i][j]);
        }
        for(int j=1;j<=m;j++) {
            arr[0][j]=arr[1][j];
        }
    }
    printf("%lli\n",pre[n][m]);
    return 0;
}
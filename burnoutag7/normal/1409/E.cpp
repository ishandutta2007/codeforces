#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,k;
    cin>>n>>k;
    vector<int> pts(1,-1e9);
    for(int i=1;i<=n;i++){
        static int x;
        cin>>x;
        pts.emplace_back(x);
    }
    for(int i=1;i<=n;i++){
        static int x;
        cin>>x;
    }
    sort(pts.begin(),pts.end());
    vector<int> dp[2];
    dp[0].resize(n+1,0);
    dp[1].resize(n+1,0);
    for(int l=1,r=1;r<=n;r++){
        while(pts[l]+k<pts[r])l++;
        dp[1][r]=max(dp[1][r-1],dp[0][l-1]+r-l+1);
        dp[0][r]=max(dp[0][r-1],r-l+1);
    }
    cout<<max(dp[0][n],dp[1][n])<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=2e5+1;
int dp[MAXN][3];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        ll k;
        cin>>n>>k;
        vector<ll> xcoords(n);
        for(int i=0;i<n;i++){
            cin>>xcoords[i];
        }
        sort(xcoords.begin(),xcoords.end());
        int trashbin;
        for(int i=0;i<n;i++)cin>>trashbin;
        for(int i=1;i<=n;i++){
            dp[i][0]=0;
            int left=lower_bound(xcoords.begin(),xcoords.end(),xcoords[i-1]-k)-xcoords.begin()-1;
            dp[i][1]=max(dp[i-1][1],dp[left+1][0]+i-1-left);
            dp[i][2]=max(dp[i-1][2],dp[left+1][1]+i-1-left);
        }
        printf("%d\n",dp[n][2]);
    }
    return 0;
}
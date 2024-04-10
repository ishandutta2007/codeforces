//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
vector<pair<int,int>> cnt[5000005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
        vector<pair<int,int>> &v=cnt[a[i]+a[j]];
        if(v.empty())v.emplace_back(i,j);
        else if(v.back().first!=i&&v.back().first!=j&&v.back().second!=i&&v.back().second!=j){
            cout<<"YES\n"<<v.back().first<<' '<<v.back().second<<' '<<i<<' '<<j;
            return 0;
        }
    }
    cout<<"NO";

    return 0;
}
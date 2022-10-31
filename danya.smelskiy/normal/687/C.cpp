#include <bits/stdc++.h>
using namespace std;

int n,k,x;
bool used[505];
bool dp[505][505];

inline void add(int x){
    for (int i=k;i>=x;--i) {
        for (int j=0;j<=k-i;++j) {
            if (dp[i-x][j]==true) dp[i][j]=true;
        }
    }
    for (int i=0;i<=k;++i)
        for (int j=0;j<=k-i;++j)
            if (dp[i][j]) dp[j][i]=true;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    dp[0][0]=true;
    for (int i=1;i<=n;++i){
        cin>>x;
        add(x);
    }
    for (int i=0;i<=k;++i) if (dp[i][k-i]==true) {
            used[i]=true;
    }
    int ans=0;
    vector<int> v;
    used[0]=true;
    for (int i=0;i<=k;++i)
    if (used[i]==true) {
        ++ans;
        v.push_back(i);
    }
    cout<<ans<<'\n';
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}
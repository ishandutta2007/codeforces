#include <bits/stdc++.h>
using namespace std;


int n;
long long ans;
long long a[100005];
vector<int> v[100005];
long long dp[100005][2];
int x,y;

void solve(int x,int y,int z){
    int q=(a[x]&(1<<z));
    if (q) q=1;
    long long zz=((1ll)<<z);
    dp[x][0]=dp[x][1]=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        solve(to,x,z);
        ans+=dp[x][0]*dp[to][1]*zz;
        ans+=dp[x][1]*dp[to][0]*zz;
        if (q==1) {
            dp[x][0]+=dp[to][1];
            dp[x][1]+=dp[to][0];
        } else {
            dp[x][0]+=dp[to][0];
            dp[x][1]+=dp[to][1];
        }
    }
    ++dp[x][q];
    ans+=zz*dp[x][1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=0;i<25;++i)
        solve(1,-1,i);
    cout<<ans;
}
#include <bits/stdc++.h>
using namespace std;
const int mx=600000;
int n,m;
int ans[mx+5];
bool dp[mx+5];
multiset<int> q;
int x;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    dp[0]=true;
    for (int i=1;i<=n;++i) {
        cin>>x;
        for (int j=mx;j>=0;--j)
            if (dp[j]) dp[j+x]=true;
    }
    q.insert(0);
    for (int i=1;i<=mx;++i) {
        ans[i]=1e9;
        if (i>m && ans[i-m-1]<1e9) {
            q.erase(q.find(ans[i-m-1]));
        }
        if (dp[i]==false) continue;
        if (q.size()==0) continue;
        int x=*q.begin();
        ans[i]=x+1;
        q.insert(ans[i]);
    }
    for (int i=mx;i>=0;--i)
    if (ans[i]<1e9) {
        cout<<i<<" "<<ans[i];
        return 0;
    }
}
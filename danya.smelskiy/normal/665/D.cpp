#include <bits/stdc++.h>
using namespace std;


int n;
int cnt;
int ans;
vector<int> res;
bool dp[2000005];
int a[1005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (a[i]==1) ++cnt;
    }
    dp[1]=true;
    for (int i=2;i<=sqrt(2000000);++i)
        if (dp[i]==false) {
            for (int j=i*i;j<=2e6;j+=i)
                dp[j]=true;
        }
    ans=1;
    res.push_back(a[1]);
    if (cnt>ans) {
        ans=cnt;
        res.clear();
        for (int i=1;i<=cnt;++i)
            res.push_back(1);
    }
    for (int i=1;i<=n;++i)
    if (a[i]>1) {
        if (dp[a[i]+1]==false) {
            ans=cnt+1;
            res.clear();
            res.push_back(a[i]);
            for (int i=1;i<=cnt;++i)
                res.push_back(1);
            break;
        }
    }
    for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;++j)
    if (dp[a[i]+a[j]]==false && ans<2) {
        ans=2;
        res.clear();
        res.push_back(a[i]);
        res.push_back(a[j]);
        break;
    }
    cout<<ans<<'\n';
    for (int i=0;i<res.size();++i)
        cout<<res[i]<<" ";
}
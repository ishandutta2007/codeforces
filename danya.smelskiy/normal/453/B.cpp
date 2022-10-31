#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
bool pr[105];
vector<int> v;
int f[105];
int dp[105][(1<<18)];
int pred[105][(1<<18)];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=2;i<=60;++i) if (pr[i]==false)
        for (int j=i*i;j<=60;j+=i)
            pr[j]=true;
    for (int i=2;i<=60;++i)
    if (pr[i]==false) {
        v.push_back(i);
    }
    for (int i=1;i<=60;++i)
        for (int j=0;j<v.size();++j)
        if (i%v[j]==0) f[i]|=(1<<j);
    int p=v.size();
    for (int i=0;i<=n;++i)
        for (int j=0;j<(1<<p);++j)
            dp[i][j]=1e9;
    dp[0][0]=0;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<(1<<p);++j) if (dp[i-1][j]!=1e9){
            for (int k=1;k<=60;++k) if (!(j&f[k])){
                int mask=(j|f[k]);
                int val=dp[i-1][j]+abs(k-a[i]);
                if (val<dp[i][mask]) {
                    dp[i][mask]=val;
                    pred[i][mask]=k;
                }
            }
        }
    }
    int val=1e9;
    int pos=0;
    for (int i=0;i<(1<<p);++i)
    if (dp[n][i]!=1e9 && dp[n][i]<val) {
        val=dp[n][i];
        pos=i;
    }
    vector<int> ans;

    for (int i=n;i>0;--i) {
        ans.push_back(pred[i][pos]);
        pos=pos^f[pred[i][pos]];
    }
    for (int i=ans.size()-1;i>=0;--i)
        cout<<ans[i]<<" ";
}
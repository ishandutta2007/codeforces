#include <bits/stdc++.h>
using namespace std;

int n;
long long a[10005];
long long dp[10005][4];
int pred[10005][4];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i) {
        dp[i][0]=-1e18;
        for (int j=1;j<=4;++j) {
            dp[i][j]=dp[i][j-1];
            pred[i][j]=i;
            long long sum=0;
            for (int k=i;k>0;--k) {
                if (j&1) sum+=a[k];
                else sum-=a[k];
                if (dp[k-1][j-1]+sum>dp[i][j]) {
                    dp[i][j]=dp[k-1][j-1]+sum;
                    pred[i][j]=k-1;
                }
            }
        }
    }
    int last=n;
    vector<int> v;
    for (int i=4;i>1;--i){
        last=pred[last][i];
        v.push_back(last);
    }
    for (int i=v.size()-1;i>=0;--i)
        cout<<v[i]<<" ";
}
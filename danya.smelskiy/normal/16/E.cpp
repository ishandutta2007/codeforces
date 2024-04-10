#include <bits/stdc++.h>
using namespace std;
int n;
long double a[100][100];
long double dp[(1<<19)];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin>>a[i][j];
    dp[(1<<n)-1]=1;
    for (int i=(1<<n)-1;i>0;--i) {
        vector<int> q;
        for (int j=0;j<n;++j)
            if (i&(1<<j)) q.push_back(j);
        long double z=q.size();
        z=(z)*(z-1)/2;
        for (int j=0;j<q.size();++j)
        for (int k=0;k<q.size();++k) if (j!=k) {
            int x=q[j];
            int y=q[k];
            dp[i^(1<<x)]+=(dp[i]*a[y][x])/z;
        }
    }
    cout<<fixed<<setprecision(6);
    for (int i=0;i<n;++i)
        cout<<dp[(1<<i)]<<" ";
}
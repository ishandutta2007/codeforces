#include <bits/stdc++.h>
using namespace std;


int n,m;
long double dp[101][101*1001];
int a[105];
long double q[101*1001];

inline void update(int l,int r,long double z){
    z/=(long double)(m-1);
    l=min(l,n*m+1);
    r=min(r,n*m);
    if (l>r) return;
    q[l]+=z;
    q[r+1]-=z;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cout<<fixed<<setprecision(10);
    if (m==1) {
        cout<<1;
        return 0;
    }
    int s=0;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        s+=a[i];
    }
    dp[0][0]=m-1;
    for (int i=0;i<n;++i) {
        for (int j=0;j<=n*m;++j) {
            q[j]=0;
        }
        for (int j=0;j<=n*m;++j) {
            update(j+1,j+a[i+1]-1,dp[i][j]);
            update(j+a[i+1]+1,j+m,dp[i][j]);
        }
        long double last=0;
        for (int j=0;j<=n*m;++j) {
            last+=q[j];
            dp[i+1][j]=last;
        }
    }
    long double ans=0;
    for (int i=0;i<s;++i)
        ans+=dp[n][i];
    cout<<ans+(long double)1;
}
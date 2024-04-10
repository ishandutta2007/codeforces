#include <bits/stdc++.h>
using namespace std;

int n;
long double a[25][25];
bool used[(1<<19)][19];
long double dp[(1<<19)][19];
long double get(int msk,int x){
    if (msk==(1<<n)-1) return x==0 ? 1 : 0;
    if (used[msk][x]) return dp[msk][x];
    used[msk][x]=true;
    long double &res=dp[msk][x];
    for (int i=0;i<n;++i) if (!(msk&(1<<i))) {
        long double q=0;
        int m=msk|(1<<i);
        q+=get(m,x)*a[x][i];
        q+=get(m,i)*a[i][x];
        res=max(res,q);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout<<fixed<<setprecision(6);
    cin>>n;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin>>a[i][j];
            long double ans=0;
    for (int i=0;i<n;++i)
    for (int j=i+1;j<n;++j) {
        int msk=(1<<i)|(1<<j);
        long double nw=0;
        nw=get(msk,i)*a[i][j]+get(msk,j)*a[j][i];
        ans=max(ans,nw);
    }
    cout<<(n==1 ? 1 : ans);
}
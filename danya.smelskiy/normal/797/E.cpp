#include <bits/stdc++.h>
using namespace std;

int n,m,x,y,dp[100005][317];
int a[100005];

inline int trivial(int x,int y){
    int ans=0;
    while (x<=n) {
        ++ans;
        x+=a[x]+y;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    int l=sqrt(n);
    int last=n;
    for (int i=n;i>0;--i){
        if (i%l==0) last=i;
        for (int j=1;j<=l;++j){
            if (j+a[i]+i>n) dp[i][j]=1;
            else dp[i][j]=dp[i+j+a[i]][j]+1;
        }
    }
    cin>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        if (y<=l) cout<<dp[x][y]<<'\n';
        else cout<<trivial(x,y)<<'\n';
    }
}
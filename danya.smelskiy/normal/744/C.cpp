#include <bits/stdc++.h>
using namespace std;

int n;
int card[100];
int r[100],b[100];
int dp[(1<<16)+5][205];
int ll1,ll2;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        char c;
        int x,y;
        cin>>c>>r[i]>>b[i];
        card[i]=(c=='R' ? 1 : 0);
        ll1+=r[i];
        ll2+=b[i];
    }
    for (int i=0;i<(1<<n);++i)
        for (int j=0;j<200;++j)
            dp[i][j]=-1e9;
    dp[0][0]=0;
    for (int i=0;i<(1<<n)-1;++i) {
        int aa=0,bb=0;
        for (int j=0;j<n;++j)
        if (i&(1<<j)) {
            aa+=card[j+1];
            bb+=1-card[j+1];
        }
        for (int j=0;j<200;++j) if (dp[i][j]!=-1e9) {
            for (int z=0;z<n;++z)
            if (!(i&(1<<z))) {
                int a1=j+min(aa,r[z+1]);
                int a2=dp[i][j]+min(bb,b[z+1]);
                dp[(i^(1<<z))][a1]=max(dp[(i^(1<<z))][a1],a2);
            }
        }
    }
    int ans=1e9;
    for (int i=0;i<200;++i)
        if (dp[(1<<n)-1][i]>-1e9) ans=min(ans,max(ll1-i,ll2-dp[(1<<n)-1][i]));
    cout<<ans+n;
}
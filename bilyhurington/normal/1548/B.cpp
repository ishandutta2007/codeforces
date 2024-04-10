#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200010];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int val[200010][20],Log[200010];
int ask(int l,int r){
    int t=Log[r-l+1];
    return gcd(val[l][t],val[r-(1<<t)+1][t]);
}
void solve(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<n;i++){
        a[i]-=a[i+1];
        if(a[i]<0) a[i]=-a[i];
    }
    if(n==1){
        puts("1");
        return;
    }
    n--;
    int ans=1;Log[0]=-1;
    for(int i=1;i<=n;i++) val[i][0]=a[i],Log[i]=Log[i>>1]+1;
    for(int i=1;i<20;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            val[j][i]=gcd(val[j][i-1],val[j+(1<<(i-1))][i-1]);
        }
    }
    for(int i=1,j=1;i<=n;i++){
        while(j<=i&&ask(j,i)==1) j++;
        if(j<=i) ans=max(ans,i-j+2);
    }
    printf("%lld\n",ans);
}
signed main(){
    scanf("%lld",&T);
    while(T--) solve();
    // system("pause");
    return 0;
}
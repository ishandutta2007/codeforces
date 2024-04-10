#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

int n,m;
long long a[100020];
long long f[100020];
long long dp[2000][2000];
vector<int> q;
long long kol[2000];
int all;

long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
long long cnk(long long x,long long y){
    if (y>x) return 0;
    long long res=f[x];
    res=(res*p(f[y],md-2))%md;
    res=(res*p(f[x-y],md-2))%md;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        int x=a[i];
        bool t=false;
        while (x) {
            if (x%10!=4 && x%10!=7) {
                t=true;
                break;
            }
            x/=10;
        }
        if (t==false) q.push_back(a[i]);
        else ++all;
    }
    sort(q.begin(),q.end());
    int last=0;
    for (int i=0;i<q.size();++i) {
        if (i==0 || q[i]!=q[i-1]) ++last;
        ++kol[last];
    }
    dp[0][0]=1;
    if (last>2000) {
        cout<<">";return 0;
    }
    for (int i=1;i<=last;++i) {
        long long res=0;
        for (int j=1;j<=last;++j) {
            dp[i][j]=(res*kol[j])%md;
            if (i==1) dp[i][j]=kol[j];
            res+=dp[i-1][j];
            res%=md;
        }
    }
    f[0]=1;
    for (int i=1;i<=n+5;++i)
        f[i]=(f[i-1]*i)%md;
        long long ans=cnk(all,m);
    for (int i=1;i<=min(m,last);++i) {
        for (int j=i;j<=last && dp[i][j];++j){
            if (i==m) {
                ans=(ans+dp[i][j])%md;
                continue;
            }
            ans=(ans+dp[i][j]*cnk(all,m-i))%md;
        }
    }
    cout<<ans;
}
#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n;
int a[305];
vector<int> v;
long long dp[305][305];
long long c[700][700];
long long f[700];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    f[0]=1;
    for (int i=1;i<=n+n;++i)
        f[i]=(f[i-1]*(long long)i)%md;
    c[0][0]=1;
    for (int i=1;i<=n+n;++i) {
        for (int j=0;j<=i;++j) {
            c[i][j]=c[i-1][j];
            if (j) {
                c[i][j]+=c[i-1][j-1];
                if (c[i][j]>=md) c[i][j]-=md;
            }
        }
    }
    for (int i=1;i<=n;++i) {
        int nw=1;
        for (int j=2;j<=sqrt(a[i]);++j) if (a[i]%j==0) {
            int jj=(j*j);
            while (a[i]%jj==0) a[i]/=jj;
            if (a[i]%j==0) {
                nw*=j;
                a[i]/=j;
            }
        }
        a[i]=a[i]*nw;
    }
    sort(a+1,a+n+1);
    int last=0;
    for (int i=1;i<=n;++i) {
        ++last;
        if (i==n || a[i]!=a[i+1]) {
            v.push_back(last);
            last=0;
        }
    }
    dp[0][0]=1;
    int kol=0;
    for (int i=0;i<v.size();++i) {
        for (int j=0;j<=kol;++j) {
            for (int s=1;s<=min(v[i],kol+1);++s) {
                for (int d=0;d<=min(j,s);++d) {
                    long long res=f[v[i]]*c[v[i]-1][s-1];
                    res%=md;
                    res=(res*c[j][d])%md;
                    res=(res*c[kol+1-j][s-d])%md;
                    res=(res*dp[i][j])%md;
                    dp[i+1][j-d+v[i]-s]+=res;
                    if (dp[i+1][j-d+v[i]-s]>=md) dp[i+1][j-d+v[i]-s]-=md;
                }
            }
        }
        kol+=v[i];
    }
    cout<<dp[(int)v.size()][0];
}
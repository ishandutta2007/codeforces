#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
#define rep(i,a,n) for(int i=(a);i<(n);++i)
vector<unsigned int> p;
vector<vector<unsigned int> > dp, tdp;
unsigned int n,m,A,B,C,D;
vector<int> a,bb;
void dfs(int u, int v) {
    if(u==n){
        int s=0;
        for(int x=v,j=1;x;) {
            if (x&1) s+=a[j];
            x>>=1;
            j++;
        }
        bb[v]=s;
        return;
    }
    dfs(u+1,v*2);
    dfs(u+1,v*2+1);
}
unsigned int cal1(unsigned int t){
    unsigned int y=t+1; if (t%2==0) t/=2; else y/=2;
    return t*y;
}
unsigned int calc2(unsigned int x){
    long long y=x+1,z=x*2+1;
    if (x%2==0) x/=2; else y/=2;
    if (z%3==0) z/=3; else if (x%3==0) x/=3; else y/=3;
    return (unsigned int)(x*y*z);
}
ULL Seed_Pool[]={911,146527,19260817,91815541};
ULL Mod_Pool[]={29123,998244353,1000000009,4294967291ull};

unsigned int solve(unsigned int n) {
    unsigned int i,j;
    vector<unsigned> roundG(4,0);
    rep(i,1,m+1) {
        tdp[0][i]=(i-1);
        tdp[1][i]=(cal1(i)-1)*C;
        tdp[2][i]=(calc2(i)-1)*B;
        tdp[3][i]=(cal1(i)*cal1(i)-1)*A;
    }
    rep(i,2,m+1){
        if (tdp[0][i]!=tdp[0][i-1]){
            roundG[0]=1; for (int w=1;w<4;w++) roundG[w]=roundG[w-1]*i;
            for (j=1;j<=min(m-1,n/i/i);j++)
                for (int w=0;w<4;w++)
                    if (i*j<m) dp[w][j]-=roundG[w]*(dp[w][i*j]-tdp[w][i-1]);
                    else dp[w][j]-=roundG[w]*(tdp[w][n/i/j]-tdp[w][i-1]);
            for (j=m;j>=i*i;j--)
                for (int w=0;w<4;w++)
                    tdp[w][j]-=roundG[w]*(tdp[w][j/i]-tdp[w][i-1]);
        }
    }
    rep(i,1,m+2) {
        dp[0][i]*=D,tdp[0][i]*=D;
    }
    unsigned int rt=0;
    for (unsigned int i=1;n/i>m;i++) {
        for (int w=0;w<4;w++) {
            rt+=(dp[w][i]-tdp[w][m]);
        }
    }
    return rt;
}
void init(){
    dp.assign(4,vector<unsigned int>(100000,0));
    tdp.assign(4,vector<unsigned int>(100000,0));
    vector<int> ip(1000000,1);
    for (unsigned int i=2;i<100000;++i) {
        if(ip[i]){
            p.push_back(i);
            for(int j=2*i;j<100000;j+=i)ip[j]=0;
        }
    }
}
void solve(){
    for (m=1;m*m<=n;m++) {
        dp[0][m]=(n/m-1);
        dp[1][m]=(cal1(n/m)-1)*C;
        dp[2][m]=(calc2(n / m)-1)*B;
        dp[3][m]=(cal1(n/m)*cal1(n/m)-1)*A;
    }
    auto ans=solve(n);
    for (auto i: p){
        if(i>m)break;
        auto curr=A*i*i*i+B*i*i+C*i+D;
        auto tmp=n;
        while (tmp){
            ans+=curr*(tmp/i);
            tmp/=i;
        }
    }
    cout << ans << endl;
}
int main() {
    init();
    cin >> n >> A >> B >> C >> D;
    solve();
    return 0;
}
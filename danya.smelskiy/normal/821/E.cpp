#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

long long n,k;
long long dp[100];
long long a[200],b[200],c[200];
struct matrix{
    vector<vector<long long > > v;
    matrix (long long n,long long m){
        v.resize(n,vector<long long>(m,0));
    }
};
inline matrix mult(matrix a,matrix b){
    matrix c(a.v.size(),b.v[0].size());
    for (long long i=0;i<c.v.size();++i) {
        for (long long j=0;j<c.v[i].size();++j) {
            c.v[i][j]=0;
            for (long long k=0;k<c.v[i].size();++k) {
                c.v[i][j]=(c.v[i][j]+a.v[i][k]*b.v[k][j])%md;
            }
        }
    }
    return c;
}
matrix p(matrix a,long long y){
    if (y<=0) {
        matrix res(a.v.size(),a.v.size());
        for (int i=0;i<a.v.size();++i)
            res.v[i][i]=1;
        return res;
    }
    if (y&1) return mult(p(a,y-1),a);
    else {
        matrix c(a.v.size(),a.v.size());
        c=p(a,y/2);
        return mult(c,c);
    }
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (long long i=1;i<=n;++i){
        cin>>a[i]>>b[i]>>c[i];
        ++c[i];
    }
    b[n]=k; dp[0]=1;
    for (long long i=1;i<=n;++i) {
        matrix aa(c[i],c[i]),bb(1,c[i]);
        for (long long j=0;j<c[i];++j)
            bb.v[0][j]=dp[j];
        for (long long j=0;j<c[i];++j)
            for (long long k=max(0ll,j-1ll);k<=min(c[i]-1,(long long)j+1ll);++k)
                aa.v[j][k]=1;
        aa=p(aa,b[i]-a[i]-1ll);
        bb=mult(bb,aa);
        long long rr=c[i];
        if (i<n) rr=min(rr,c[i+1]);
        if (a[i]==b[i]) continue;
        for (long long j=0;j<=20;++j)
            dp[j]=0;
        for (long long j=0;j<rr;++j)
            for (long long k=max(0ll,j-1ll);k<=min((long long)bb.v[0].size()-1,j+1ll);++k)
                dp[j]=(dp[j]+bb.v[0][k])%md;
    }
    cout<<dp[0];
}
#include <bits/stdc++.h>
using namespace std;

const long long md=1e9+7;

struct matrix{
    long long a[101][101];
};
matrix dp;
int kol[100];
int n,m,k,x;

inline matrix mult(matrix a,matrix b){
    matrix c;
    for (int i=0;i<x;++i)
    for (int j=0;j<x;++j) {
        c.a[i][j]=0;
        for (int k=0;k<x;++k)
            c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%md;
    }
    return c;
}

matrix p(matrix x,int y){
    if (y<=1) return x;
    if (y&1) return mult(x,p(x,y-1));
    matrix z=p(x,y/2);
    return mult(z,z);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k>>x;
    for (int i=1;i<=n;++i) {
        int x; cin>>x;
        ++kol[x];
    }
    for (int i=0;i<x;++i)
        for (int j=0;j<10;++j)
            dp.a[i][(i*10+j)%x]+=kol[j];
    dp=p(dp,m);
    cout<<dp.a[0][k];
}
#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;


int n,l,m;

struct matrix {
    long long a[102][102];
};
matrix a,in;
int x;
int xx[1000005];
inline matrix mult(matrix a,matrix b){
    matrix c;
    for (int i=0;i<m;++i)
    for (int j=0;j<m;++j) {
        c.a[i][j]=0;
        for (int k=0;k<m;++k)
            c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%md;
    }
    return c;
}
matrix p(matrix a,int y){
    if (y==0) {
        matrix res;
        for (int i=0;i<m;++i){
            for (int j=0;j<m;++j)
                res.a[i][j]=0;
            res.a[i][i]=1;
        }
        return res;
    }
    if (y&1) return mult(p(a,y-1),a);
    matrix res=p(a,y/2);
    return mult(res,res);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>l>>m;
    for (int i=1;i<=n;++i) {
        cin>>x;
        x%=m;
        ++in.a[0][x];
    }
    for (int i=1;i<=n;++i) {
        cin>>x;
        xx[i]=x;
        x%=m;
        ++a.a[0][x];
    }
    for (int i=1;i<m;++i)
    for (int j=0;j<m;++j){
        a.a[i][(i+j)%m]=a.a[0][j];
        in.a[i][(i+j)%m]=in.a[0][j];
    }
    matrix res;
    res=p(a,l-2);
    res=mult(res,in);
    long long ans=0;
    for (int i=1;i<=n;++i) {
        cin>>x;
        x=(x+xx[i])%m;
        ans=(ans+res.a[0][(m-x)%m]);
        if (ans>md) ans-=md;
    }
    cout<<ans;
}
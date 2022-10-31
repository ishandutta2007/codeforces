#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,m;
int a[105];


struct mt{
    int a[101][101];
};
mt b;
inline mt mult(mt a,mt b){
    mt res;
    for (int i=0;i<n;++i)
    for (int j=0;j<n;++j){
        res.a[i][j]=-inf;
        for (int k=0;k<n;++k)
            res.a[i][j]=max(res.a[i][j],a.a[i][k]+b.a[k][j]);
    }
    return res;
}
mt p(mt x,int y){
    if (y<=1) return x;
    if (y&1) return mult(x,p(x,y-1));
    mt c=p(x,y>>1);
    return mult(c,c);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
    for (int j=0;j<n;++j) {
        if (a[j]<a[i]) b.a[i][j]=-inf;
        else {
        b.a[i][j]=1;
        for (int k=0;k<j;++k)
            if (a[k]<=a[j]) b.a[i][j]=max(b.a[i][j],b.a[i][k]+1);
        }
    }
    b=p(b,m);
    int res=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            res=max(res,b.a[i][j]);
    cout<<res;
}
#include <bits/stdc++.h>
using namespace std;



struct matrix{
    int n;
    long long a[50][50];
};
int n,m;
int a[100];
int b[100];
long long dp[100][100];
inline matrix mult(matrix a,matrix b){
    matrix c;
    c.n=a.n;
    for (int i=0;i<=c.n;++i)
        for (int j=0;j<=c.n;++j)
            c.a[i][j]=1e15;
    for (int i=0;i<a.n;++i) {
        for (int j=0;j<a.n;++j) {
            for (int k=0;k<a.n;++k)
                c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
        }
    }
    return c;
}
matrix p(matrix a,int y){
    if (y==1) return a;
    if (y&1) return mult(p(a,y-1),a);
    matrix c=p(a,y/2);
    return mult(c,c);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>b[i];

    matrix q;
    q.n=n+n;
    for (int i=0;i<=n+n;++i) {
        for (int j=0;j<=n;++j)
            for (int k=0;k<=n+n;++k)
                dp[j][k]=1e9;
        dp[0][i]=0;
        for (int j=0;j<n;++j) {
            for (int k=0;k<=n+n;++k) {
                if (k) dp[j+1][k-1]=min(dp[j+1][k-1],dp[j][k]+b[j]);
                if (k<n+n) dp[j+1][k+1]=min(dp[j+1][k+1],dp[j][k]+a[j]);
            }
        }
        for (int j=0;j<=n+n;++j)
            q.a[i][j]=dp[n][j];
    }
    q=p(q,m);
    cout<<q.a[0][0];
}
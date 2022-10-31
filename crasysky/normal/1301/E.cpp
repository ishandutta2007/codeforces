#include <bits/stdc++.h>
using namespace std;
const int N=502;
int n,m,s[4][N][N],sum[N][N][N];
bool Q(int t,int l1,int l2,int r1,int r2){
    if (l1<1||l2<1||r1>n||r2>m) return false;
    return s[t][r1][r2]-s[t][l1-1][r2]-s[t][r1][l2-1]+s[t][l1-1][l2-1]==(r1-l1+1)*(r2-l2+1);
}
bool Qs(int t,int l1,int r1,int l2,int r2){
    if (l1>r1||l2>r2) return false;
    return sum[t][r1][r2]-sum[t][l1-1][r2]-sum[t][r1][l2-1]+sum[t][l1-1][l2-1];
}
int main(){
    int q; cin>>n>>m>>q;
    for (int i=1;i<=n;++i){
        string str; cin>>str;
        for (int j=1;j<=m;++j)
            if (str[j-1]=='R') s[0][i][j]=1;
            else if (str[j-1]=='G') s[1][i][j]=1;
            else if (str[j-1]=='Y') s[2][i][j]=1;
            else if (str[j-1]=='B') s[3][i][j]=1;
    }
    for (int t=0;t<4;++t)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                s[t][i][j]+=s[t][i-1][j]+s[t][i][j-1]-s[t][i-1][j-1];
    for (int i=1;i<n;++i)
        for (int j=1;j<m;++j){
            int t=0;
            while (Q(0,i-t,j-t,i,j)&&Q(1,i-t,j+1,i,j+t+1)&&Q(2,i+1,j-t,i+t+1,j)&&Q(3,i+1,j+1,i+t+1,j+t+1))
                sum[++t][i][j]=1;
        }
    for (int t=1;t<=min(n,m);++t)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
                sum[t][i][j]+=sum[t][i-1][j]+sum[t][i][j-1]-sum[t][i-1][j-1];
    while (q--){
        int l1,r1,l2,r2; scanf("%d%d%d%d",&l1,&l2,&r1,&r2);
        int l=1,r=n;
        while (l<=r){
            int m=l+r>>1;
            if (Qs(m,l1+m-1,r1-m,l2+m-1,r2-m))
                l=m+1;
            else
                r=m-1;
        }
        cout<<4*(l-1)*(l-1)<<endl;
    }
}
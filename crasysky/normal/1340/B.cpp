#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=2e3+3;
int A[10][7]={
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1},
};
int a[N][15],c[N][10],f[N][N],ans[N];
int read(){
    int c=0; char ch=getchar();
    while (ch<'0'||'9'<ch) ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c;
}
int main(){
    int n=read(),K=read();
    rep(i,1,n){
        char s[10]; scanf("%s",s);
        rep(j,0,6) a[i][j]=s[j]-'0';
        rep(j,0,9)
            rep(k,0,6)
                if (a[i][k]&&!A[j][k]){ c[i][j]=-1; break; }
                else c[i][j]+=A[j][k]-a[i][k];
    }
    f[n+1][0]=1;
    per(i,n,1)
        rep(j,0,9)
            if (c[i][j]!=-1)
                rep(k,c[i][j],K)
                    f[i][k]|=f[i+1][k-c[i][j]];
    int t=0;
    rep(i,1,n){
        bool sol=false;
        per(j,9,0)
            if (c[i][j]!=-1&&K-t>=c[i][j]&&f[i+1][K-t-c[i][j]]){
                t+=c[i][j],ans[i]=j,sol=true; break;
            }
        if (!sol){ cout<<-1<<endl; return 0; }
    }
    rep(i,1,n) printf("%d",ans[i]);
    return 0;
}
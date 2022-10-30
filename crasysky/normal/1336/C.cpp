#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=3003,P=998244353;
int a[N],b[N],f[N][N],h[N][N],g[N][N];
int add(int x,int y){ x+=y; return x>=P?x-P:x; }
signed main(){
    static char s[N],t[N]; scanf("%s%s",s,t);
    int n=strlen(s),m=strlen(t);
    rep(i,1,n) a[i]=s[i-1]-'a'+1;
    rep(i,1,m) b[i]=t[i-1]-'a'+1;
    rep(i,1,m-1) if (b[i]==a[1]) f[i][i]=1;
    if (b[m]==a[1]) h[m][1]=1;
    per(l,n,1){
        rep(r,l+1,n-1){
            if (a[r-l+1]==b[l]) f[l][r]=add(f[l][r],f[l+1][r]);
            if (a[r-l+1]==b[r]) f[l][r]=add(f[l][r],f[l][r-1]);
        }
        if (a[m-l+1]==b[m]) h[l][m-l+1]=add(h[l][m-l+1],f[l][m-1]);
        rep(i,m-l+1,n){
            h[l][i]=add(h[l][i],h[l][i-1]);
            if (a[i]==b[l]) h[l][i]=add(h[l][i],h[l+1][i-1]);
        }
    }
    g[1][0]=1;
    rep(i,1,n-1)
        rep(j,0,m)
            if (g[i][j]){
                if (b[m-j]==a[i+1]) g[i+1][j+1]=add(g[i+1][j+1],g[i][j]);
                g[i+1][j]=add(g[i+1][j],g[i][j]);
                if (j==0) g[i+1][j]=add(g[i+1][j],g[i][j]);
            }
    int sum=0;
    rep(i,1,n) sum=add(sum,h[1][i]);
    rep(i,1,n) sum=add(sum,g[i][m]);
    cout<<(sum+sum)%P<<endl;
    return 0;
}
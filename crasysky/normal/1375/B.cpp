#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e3+3,INF=1e9;
int n,m,a[N][N];
int v(int x,int y){
    if (x>n||y>m) return 0;
    return (a[x-1][y]>0)+(a[x][y-1]>0)+(a[x+1][y]>0)+(a[x][y+1]>0);
}
int main(){
    int T; cin>>T;
    while (T--){
        cin>>n>>m;
        rep(i,0,n+1) rep(j,0,m+1) a[i][j]=0;
        rep(i,1,n)
            rep(j,1,m) scanf("%d",&a[i][j]);
        rep(i,1,n)
            rep(j,1,m)
                if (a[i][j]==0)
                    if (v(i+1,j)<a[i+1][j]||v(i,j+1)<a[i][j+1]||v(i-1,j)<a[i-1][j]||v(i,j-1)<a[i][j-1])
                        a[i][j]=1;
        bool f=false;
        rep(i,1,n)
            rep(j,1,m){
                if (a[i][j]>0&&v(i,j)<a[i][j]){ f=true; break; }
                if (a[i][j]>0) a[i][j]=v(i,j);
            }
        if (f){ puts("NO"); continue; }
        puts("YES");
        rep(i,1,n){
            rep(j,1,m) printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
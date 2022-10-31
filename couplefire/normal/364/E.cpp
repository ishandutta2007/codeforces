#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=2555;
int n,m,k,s[N][N];
char b[N][N];
LL ans;
inline int sum(int r1,int r2,int c1,int c2){
    return s[r2][c2]-s[r2][c1-1]-s[r1-1][c2]+s[r1-1][c1-1];
}
int A[N][N][7],B[N][N][7];
void solve(int l,int r,int L,int R){
    if(l==r&&L==R){
        ans+=k==(b[l][L]^'0');
        return;
    }
    if(r-l+1>R-L+1){
        const int mid=l+r>>1;
        for(int i=L;i<=R;++i)for(int j=i;j<=R;++j)memset(A[i][j],0,sizeof**A),memset(B[i][j],0,sizeof**B);
        for(int K=0;K<=k;++K){
            for(int x=L;x<=R;++x){
                int up=l,down=r;
                for(int y=x;y<=R;++y){
                    while(up<=mid&&sum(up,mid,x,y)>K)++up;
                    while(down>mid&&sum(mid+1,down,x,y)>K)--down;
                    A[x][y][K]=mid-up+1,B[x][y][K]=down-mid;
                }
            }
        }
        for(int x=L;x<=R;++x)for(int y=x;y<=R;++y)for(int u=0;u<=k;++u)ans+=(A[x][y][u]-(u?A[x][y][u-1]:0))*(B[x][y][k-u]-(k-u?B[x][y][k-u-1]:0));
        solve(l,mid,L,R),solve(mid+1,r,L,R);
    }else{
        const int mid=L+R>>1;
        for(int i=l;i<=r;++i)for(int j=i;j<=r;++j)memset(A[i][j],0,sizeof**A),memset(B[i][j],0,sizeof**B);
        for(int K=0;K<=k;++K){
            for(int x=l;x<=r;++x){
                int up=L,down=R;
                for(int y=x;y<=r;++y){
                    while(up<=mid&&sum(x,y,up,mid)>K)++up;
                    while(down>mid&&sum(x,y,mid+1,down)>K)--down;
                    A[x][y][K]=mid-up+1,B[x][y][K]=down-mid;
                }
            }
        }
        for(int x=l;x<=r;++x)for(int y=x;y<=r;++y)for(int u=0;u<=k;++u)ans+=(A[x][y][u]-(u?A[x][y][u-1]:0))*(B[x][y][k-u]-(k-u?B[x][y][k-u-1]:0));
        solve(l,r,L,mid),solve(l,r,mid+1,R);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)cin>>b[i]+1;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
    s[i][j]=(b[i][j]^'0')+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    solve(1,n,1,m);
    cout<<ans<<'\n';
    return 0;
}
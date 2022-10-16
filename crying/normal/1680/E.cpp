#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10,INF=1e9;
int T,n,ans;
int a[2][MAXN],b[2][MAXN];
int f[MAXN][4],g[MAXN][4];
void solve(int a[][MAXN],int f[][4]){
    rep(i,0,n)rep(j,0,3)f[i][j]=INF;
    f[0][0]=0;
    rep(i,1,n)rep(j,0,3){
        int state=j;
        if(a[0][i])state|=1;
        if(a[1][i])state|=2;
        if(state==0){
            f[i][0]=min(f[i][0],f[i-1][j]);
        }else if(state==1){
            f[i][1]=min(f[i][1],f[i-1][j]+1);
            f[i][2]=min(f[i][2],f[i-1][j]+2);
        }else if(state==2){
            f[i][1]=min(f[i][1],f[i-1][j]+2);
            f[i][2]=min(f[i][2],f[i-1][j]+1);
        }else{
            f[i][1]=min(f[i][1],f[i-1][j]+2);
            f[i][2]=min(f[i][2],f[i-1][j]+2);
            f[i][3]=min(f[i][3],f[i-1][j]+3);
        }
    }
}
void solve(){
    ans=INF;
    cin>>n;
    char tmp;
    rep(i,0,1){
        rep(j,1,n){
            cin>>tmp;
            a[i][j]=(tmp=='*');
            b[i][n-j+1]=a[i][j];
        }
    }
    solve(a,f);solve(b,g);
    rep(i,0,1)rep(j,1,n){
        rep(l,0,3)rep(r,0,3){
            int state=l|r;
            if(a[0][j])state|=1;
            if(a[1][j])state|=2;
            if(i==0)state&=2;
            else state&=1;
            ans=min(ans,f[j-1][l]+g[n-j][r]+(state>0));
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}
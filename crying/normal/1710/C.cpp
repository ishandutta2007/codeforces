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
const int MAXN=2e5+10,mod=998244353;
int n,S[MAXN];
char s[MAXN];

void add(ll& x,ll y){
    x=(x+y)%mod;
}
ll dp[2][2][2][2][2][2][2],ans;
int main(){
    cin>>(s+1);
    n=strlen(s+1);
    rep(i,1,n)S[i]=s[i]-'0';

    dp[0][0][0][0][0][0][0]=1;
    
    rep(i,0,n-1){
        memset(dp[(i+1)&1],0,sizeof dp[(i+1)&1]);
        rep(lx,0,1)rep(ly,0,1)rep(lz,0,1)rep(a,0,1)rep(b,0,1)rep(c,0,1)rep(x,0,1)rep(y,0,1)rep(z,0,1){
            if( (!lx && x>S[i+1]) || (!ly && y>S[i+1]) || (!lz && z>S[i+1]) )continue;
            int nx=lx || (x<S[i+1]),ny=ly || (y<S[i+1]),nz=lz || (z<S[i+1]);
            int va=x^y,vb=x^z,vc=y^z;
            int na=a,nb=b,nc=c;
            if(va || vb || vc){
                na|=(!va);
                nb|=(!vb);
                nc|=(!vc);
            }
            add(dp[(i+1)&1][nx][ny][nz][na][nb][nc],dp[i&1][lx][ly][lz][a][b][c]);
        }
    }

    rep(i,0,1)rep(j,0,1)rep(k,0,1)add(ans,dp[n&1][i][j][k][1][1][1]);
    cout<<ans;
    return 0;
}
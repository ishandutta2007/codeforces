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
const int MAXN=3e5+10;
int T,n,A[MAXN];
int f[MAXN];
int qry(int S,int x){return S>>x&1;}
int qryp(int S,int x){return S&( ((1<<30)-1)^((1<<x)-1) );}
int g[35][2][2][MAXN+200];
void solve(){
    cin>>n;
    rep(i,0,n-1)cin>>A[i],f[i]=0;

    rep(i,1,30)rep(a,0,1)rep(b,0,1)rep(x,0,n+200)g[i][a][b][x]=0;
    
    rep(i,0,n-1){
        f[i]=1;
        //-j
        per(j,30,1){
            int val=qryp(A[i]^i,j);
            int b=qry(i,j-1),c=qry(A[i],j-1);
            //a^b<c^d;
            rep(a,0,1)rep(d,0,1){
                if((a^b)<(c^d)){
                    f[i]=max(f[i],g[j][a][d][val]+1);
                }
            }
        }
        rep(j,1,30){
            int val=qryp(A[i]^i,j);
            int a=qry(A[i],j-1),d=qry(i,j-1);
            g[j][a][d][val]=max(g[j][a][d][val],f[i]);
        }
    }

    int ans=0;
    rep(i,0,n-1)ans=max(ans,f[i]);
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}
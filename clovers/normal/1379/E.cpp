/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=100005;
int n,k,bl[N],fa[N],mx[N],pos[N],top=0;
int vis[25][25];
bool judge(int n,int k){
    if(n%2==0||k<0) return 0;
    if(n<=10&&!vis[n][k]) return 0;
    if(k>mx[n]) return 0;
    if(bl[n]&&k==1) return 0;
    if(!bl[n]&&k==0) return 0;
    return 1;
}

void solve(int l,int r,int F,int k){
    int sz=r-l+1; fa[l]=F;
    if(sz==1) return;
    if(sz==3){solve(l+1,l+1,l,0); solve(r,r,l,0); return;}
    if(sz==5){solve(l+1,l+1,l,0); solve(l+2,r,l,1); return;}
    if(sz==7){
        if(k==0){solve(l+1,l+3,l,0); solve(l+4,r,l,0); return;}
        else{solve(l+1,l+1,l,0); solve(l+2,r,l,1); return;}
    }
    if(sz==9){
        if(k==1){solve(l+1,l+1,l,0); solve(l+2,r,l,0); return;}
        if(k==3){solve(l+1,l+1,l,0); solve(l+2,r,l,2); return;}
    }
    if(k==mx[sz]){solve(l+1,l+1,l,0); solve(l+2,r,l,k-1); return;}
    for(int x=1;x<=19;x+=2){
        for(int i=0;i<=min(8,k);i++){
            int y=sz-x-1;
            int bl=(x*2<=y||y*2<=x);
            if(vis[x][i]&&judge(y,k-i-bl)){
                solve(l+1,l+x,l,i); solve(l+x+1,r,l,k-i-bl);
                return;
            }
        }
    }
    for(int t=1;t<=top;t++){
        int x=pos[t],y=sz-x-1;
        int bl=(x*2<=y||y*2<=x);
        if(y<0) break;
        for(int i=min(k,mx[x]);i>=0;i--){
            if(judge(x,i)&&judge(y,k-i-bl)){
                solve(l+1,l+x,l,i); solve(l+x+1,r,l,k-i-bl);
                return;
            }
        }
    }
}

int main()
{
    n=read(); k=read();
    vis[1][0]=1; vis[3][0]=1; vis[5][1]=1; vis[7][0]=1; vis[7][2]=1; vis[9][1]=1; vis[9][3]=1;
    mx[1]=1; mx[3]=1; mx[5]=1; mx[7]=2; mx[9]=3;
    for(int i=1;i<=n;i=i*2+1) bl[i]=1,pos[++top]=i;
    for(int i=11;i<=n;i+=2) mx[i]=(i-3)/2;
    for(int i=11;i<=20;i+=2){
        for(int j=0;j<=i;j++) vis[i][j]=judge(i,j);
    }
    if(!judge(n,k)){puts("NO"); return 0;}
    puts("YES");
    solve(1,n,0,k);
    for(int i=1;i<=n;i++) printf("%d ",fa[i]); puts("");
    return 0;
}
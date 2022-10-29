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
const int N=1005;
int a[N][N],L[N][N],R[N][N],U[N][N],D[N][N],n,m,q,mi[N];
void update(int x,int y){
    L[x][y]=R[x][y]=U[x][y]=D[x][y]=0;
    int xx,yy;
    xx=x,yy=y; while(a[xx][yy]) U[x][y]++,xx--;
    xx=x,yy=y; while(a[xx][yy]) D[x][y]++,xx++;
    xx=x,yy=y; while(a[xx][yy]) L[x][y]++,yy--;
    xx=x,yy=y; while(a[xx][yy]) R[x][y]++,yy++;
}

int main()
{
    n=read(); m=read(); q=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) a[i][j]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) if(a[i][j]){
            L[i][j]=L[i][j-1]+1;
            U[i][j]=U[i-1][j]+1;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--) if(a[i][j]){
            R[i][j]=R[i][j+1]+1;
            D[i][j]=D[i+1][j]+1;
        }
    }
    while(q--){
        int opt=read(),x=read(),y=read();
        if(opt==1){
            a[x][y]^=1;
            for(int i=1;i<=m;i++) update(x,i);
            for(int i=1;i<=n;i++) update(i,y);
        }
        else{
            int ans=max(max(U[x][y],D[x][y]),max(L[x][y],R[x][y]));
            mi[y]=U[x][y];
            for(int i=y-1;i>=1;i--) mi[i]=min(U[x][i],mi[i+1]);
            for(int i=y+1;i<=m;i++) mi[i]=min(U[x][i],mi[i-1]);
            int l=y,r=y; mi[0]=0; mi[m+1]=0;
            while(true){
                if(mi[l]==0||mi[r]==0) break;
                while(mi[l-1]==mi[l]&&l!=1) l--;
                while(mi[r+1]==mi[r]&&r!=m) r++;
                checkmax(ans,(r-l+1)*min(mi[l],mi[r]));
                if(mi[l-1]<mi[r+1]) r++;
                else l--;
            }
            mi[y]=D[x][y];
            for(int i=y-1;i>=1;i--) mi[i]=min(D[x][i],mi[i+1]);
            for(int i=y+1;i<=m;i++) mi[i]=min(D[x][i],mi[i-1]);
            l=y,r=y; mi[0]=0; mi[m+1]=0;
            while(true){
                if(mi[l]==0||mi[r]==0) break;
                while(mi[l-1]==mi[l]&&l!=1) l--;
                while(mi[r+1]==mi[r]&&r!=m) r++;
                checkmax(ans,(r-l+1)*min(mi[l],mi[r]));
                if(mi[l-1]<mi[r+1]) r++;
                else l--;
            }

            mi[x]=L[x][y];
            for(int i=x-1;i>=1;i--) mi[i]=min(L[i][y],mi[i+1]);
            for(int i=x+1;i<=n;i++) mi[i]=min(L[i][y],mi[i-1]);
            l=x,r=x; mi[0]=0; mi[n+1]=0;
            while(true){
                if(mi[l]==0||mi[r]==0) break;
                while(mi[l-1]==mi[l]&&l!=1) l--;
                while(mi[r+1]==mi[r]&&r!=n) r++;
                checkmax(ans,(r-l+1)*min(mi[l],mi[r]));
                if(mi[l-1]<mi[r+1]) r++;
                else l--;
            }
            mi[x]=R[x][y];
            for(int i=x-1;i>=1;i--) mi[i]=min(R[i][y],mi[i+1]);
            for(int i=x+1;i<=n;i++) mi[i]=min(R[i][y],mi[i-1]);
            l=x,r=x; mi[0]=0; mi[n+1]=0;
            while(true){
                if(mi[l]==0||mi[r]==0) break;
                while(mi[l-1]==mi[l]&&l!=1) l--;
                while(mi[r+1]==mi[r]&&r!=n) r++;
                checkmax(ans,(r-l+1)*min(mi[l],mi[r]));
                if(mi[l-1]<mi[r+1]) r++;
                else l--;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
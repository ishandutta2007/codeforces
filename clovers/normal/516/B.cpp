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
const int N=2005;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m,deg[N][N],vis[N][N]; char s[N][N];
void GG(){puts("Not unique"); exit(0);}
void shu(int x,int y){s[x][y]='^'; s[x+1][y]='v';}
void heng(int x,int y){s[x][y]='<'; s[x][y+1]='>';}
queue<pii> q;
void update(int i,int j){
    deg[i][j]=0;
    for(int d=0;d<4;d++){
        int x=i+dx[d],y=j+dy[d];
        if(x<1||x>n||y<1||y>m) continue;
        if(s[x][y]=='.') deg[i][j]++;
    }
    if(deg[i][j]==1&&!vis[i][j]) vis[i][j]=1,q.push(mk(i,j));
}

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) if(s[i][j]=='.'){
            update(i,j);
        }
    }
    while(!q.empty()){
        pii u=q.front(); q.pop();
        if(s[u.first][u.second]!='.') continue;
        int flag=0;
        for(int i=0;i<4;i++){
            int x=u.first+dx[i],y=u.second+dy[i];
            if(x<1||x>n||y<1||y>m) continue;
            if(s[x][y]=='.'){
                if(i==0) heng(u.first,u.second);
                else if(i==1) heng(x,y);
                else if(i==2) shu(u.first,u.second);
                else shu(x,y);
                for(int d=0;d<4;d++){
                    int xx=x+dx[d],yy=y+dy[d];
                    if(xx<1||xx>n||yy<1||yy>m) continue;
                    if(s[xx][yy]=='.') update(xx,yy);
                }
                flag=1; break;
            }
        }
        if(!flag) GG();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) if(s[i][j]=='.') GG();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%c",s[i][j]);
        puts("");
    }
    return 0;
}
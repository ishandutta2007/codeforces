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
int n,m,sx,sy,suml,sumr;
char s[N][N];
struct node{
    int x,y,restl,restr;
};
queue<node> q;
int ans=0,vis[N][N];
pii a[N][N];
void bfs(){
    a[sx][sy]=mk(suml,sumr); vis[sx][sy]=1; ans++;
    q.push({sx,sy,suml,sumr});
    while(!q.empty()){
        node now=q.front(); q.pop();
        int x=now.x,y=now.y;
        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i]; node tmp=now;
            if(xx<1||yy<1||xx>n||yy>m||s[xx][yy]=='*')
                continue;
            if(i==0&&tmp.restr==0) continue;
            if(i==0) tmp.restr--;
            if(i==1&&tmp.restl==0) continue;
            if(i==1) tmp.restl--;
            if(!vis[xx][yy]){
                a[xx][yy]=mk(tmp.restl,tmp.restr);
                q.push({xx,yy,tmp.restl,tmp.restr});
                vis[xx][yy]=1; ans++;
            }
            else{
                if(tmp.restl<=a[xx][yy].first&&tmp.restr<=a[xx][yy].second) continue;
                else{
                    a[xx][yy]=mk(tmp.restl,tmp.restr);
                    q.push({xx,yy,tmp.restl,tmp.restr});
                }
            }
        }
    } 
}

int main()
{
    n=read(); m=read(); sx=read(); sy=read();
    suml=read(); sumr=read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    bfs();
    cout<<ans<<endl;
    return 0;
}
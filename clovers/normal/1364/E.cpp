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
const int N=2500;
int n,a[N],p[N],mp[N][N];
int ask(int x,int y){
    if(x>y) swap(x,y);
    if(mp[x][y]) return mp[x][y];
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int ret=read();
    return mp[x][y]=ret;
}

int main()
{
    srand(time(0));
    n=read();
    for(int i=1;i<=n;i++) p[i]=i;
    random_shuffle(p+1,p+n+1);
    int pos1=1,pos2=2,now=ask(p[pos1],p[pos2]);
    for(int i=3;i<=n;i++){
        int typ=rand()%2;
        if(typ){
            int x=ask(p[pos1],p[i]);
            if(x<now) now=x,pos2=i;
            else if(x==now) pos1=i,now=ask(p[pos2],p[i]);
        }
        else{
            int x=ask(p[pos2],p[i]);
            if(x<now) now=x,pos1=i;
            else if(x==now) pos2=i,now=ask(p[pos1],p[i]);
        }
    }
    int bl=1;
    for(int i=1;i<=n;i++) if(i!=pos1&&i!=pos2){
        if(bl){
            int x1=ask(p[i],p[pos1]);
            int x2=ask(p[i],p[pos2]);
            a[p[i]]=min(x1,x2);
            if(x1!=x2) bl=0;
            if(x1>x2) swap(pos1,pos2);
        }
        else a[p[i]]=ask(p[i],p[pos1]);
    }
    a[p[pos2]]=ask(p[pos1],p[pos2]);
    printf("! ");
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    fflush(stdout);
    return 0;
}
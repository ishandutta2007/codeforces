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
struct node1{
    int ti,x,cost;
    bool operator < (const node1 &rhs) const{
        return ti<rhs.ti;
    }
}a[N]; int topa=0;
struct node2{
    int ti,x,cost;
    bool operator < (const node2 &rhs) const{
        return ti<rhs.ti;
    }
}b[N]; int topb=0;
int n,m,k; ll ans=INF;
ll lst=0,fst=0;
int nxt[N],now[N];
int flag=0,cnt=0,mi[N];

int main()
{
    n=read(); m=read(); k=read();
    for(int i=1;i<=m;i++){
        int d=read(),x=read(),y=read(),c=read();
        if(!y) a[++topa]={d,x,c};
        else b[++topb]={d,y,c};
    }
    sort(a+1,a+topa+1); sort(b+1,b+topb+1);
    for(int i=1;i<=n;i++) now[i]=topb+1;
    for(int i=topb;i>=1;i--){
        nxt[i]=now[b[i].x];
        now[b[i].x]=i;
        if(nxt[i]!=topb+1) checkmin(b[i].cost,b[nxt[i]].cost);
    }
    for(int i=1;i<=n;i++){
        if(now[i]==topb+1){puts("-1"); return 0;}
        lst+=b[now[i]].cost;
    } 
    memset(mi,0x3f,sizeof(mi));
    for(int i=1,j=1;i<=topa;i++){
        int kk=1;
        while(b[j].ti-a[i].ti-1<k&&j<=topb){
            lst-=b[j].cost;
            if(nxt[j]==topb+1) kk=0;
            lst+=b[nxt[j]].cost;
            j++;
        }
        if(j>topb||kk==0) break;
        if(mi[a[i].x]>=inf) cnt++,mi[a[i].x]=a[i].cost,fst+=a[i].cost;
        else if(mi[a[i].x]>a[i].cost){
            fst+=a[i].cost-mi[a[i].x];
            mi[a[i].x]=a[i].cost;
        }
        if(cnt==n) checkmin(ans,fst+lst);
    }
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
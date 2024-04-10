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
const int N=300005;
int n,a[N],b[N];
struct node{
    int x,id;
    bool operator < (const node &rhs) const{
        return x<rhs.x;
    }
}p[N];
int pre[N],vis[N],nxt[N];
vector<int> v[N];
void bfs(){
    memset(nxt,-1,sizeof(nxt));
    for(int i=1;i<=n;i++) v[i+b[i]].push_back(i);
    for(int i=1;i<=n;i++) p[i]={i-a[i],i};
    sort(p+1,p+n+1);
    int lst=0,i=1;
    int flag=1;
    while(flag){
        int tmp=0; flag=0; 
        while(i<=n&&p[i].x<=lst){
            nxt[p[i].id]=lst;
            flag=1; 
            for(auto &x : v[p[i].id]) checkmax(tmp,x);
            i++;
        }
        lst=tmp;
    }
    if(nxt[n]==-1) puts("-1");
    else{
        int x=n;
        vector<int> ans;
        do{
            x=nxt[x];
            ans.push_back(x);
            x+=b[x];
        }while(x);
        printf("%d\n",sz(ans));
        for(auto &u : ans) printf("%d ",u);
    }
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();
    bfs();
    return 0;
}
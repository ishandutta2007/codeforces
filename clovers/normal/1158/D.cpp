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
struct node{
    int x,y,id;
}a[N],b[N];
bool cmprad(node A,node B){return (ll)A.x*B.y-(ll)A.y*B.x>0;}
bool cmpx(node A,node B){return A.x<B.x||(A.x==B.x&&A.y<B.y);}
int n,vis[N];
char s[N];

int main()
{
    n=read(); 
    for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].id=i;
    scanf("%s",s+1);
    int p=1;
    for(int i=2;i<=n;i++) if(cmpx(a[i],a[p])) p=i;
    printf("%d ",p); vis[p]=1;
    int nowx=a[p].x,nowy=a[p].y;
    for(int rnd=2;rnd<n;rnd++){
        vector<node> v;
        for(int i=1;i<=n;i++) if(!vis[a[i].id])
            v.push_back({a[i].x-nowx,a[i].y-nowy,a[i].id});
        sort(v.begin(),v.end(),cmprad);
        node u=(s[rnd-1]=='L' ? v[0] : v.back());
        vis[u.id]=1; nowx=a[u.id].x; nowy=a[u.id].y;
        printf("%d ",u.id);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) printf("%d\n",i);
    return 0;
}
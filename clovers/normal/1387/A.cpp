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
const double eps=1e-9;
int n,m; vector<pii> v[N];
struct node{
    int a,b;//ax+b
    bool operator < (const node &rhs) const{
        if(a==0) return 1;
        if(rhs.a==0) return 0;
        return -1.0*b/a<-1.0*rhs.b/rhs.a;
    }
    bool operator == (const node &rhs) const{
        return a==rhs.a&&b==rhs.b;
    }
    bool operator != (const node &rhs) const{
        return a!=rhs.a||b!=rhs.b;
    }
}p[N];
node operator + (node &A,node &B){return {A.a+B.a,A.b+B.b};}
node operator - (node &A,node &B){return {A.a-B.a,A.b-B.b};}
bool cmp(int x,int y){return p[x]<p[y];}
int vis[N]; double val[N],cst;
vector<int> seq;
void dfs(int u){
    vis[u]=1; seq.push_back(u);
    // out(u); out(p[u].a); outln(p[u].b);
    for(auto &e : v[u]){
        int to=e.first,w=e.second;
        node s={0,w};
        if(vis[to]){
            node sum=p[u]+p[to];
            sum=sum-s;
            if(sum.a==0){
                if(sum.b!=0){puts("NO"); exit(0);}
            }
            else{
                if(cst==-1e9) cst=-1.0*sum.b/sum.a;
                else if(fabs(-1.0*sum.b/sum.a-cst)>eps){puts("NO"); exit(0);}
            }
        }
        else p[to]=s-p[u],dfs(to);
    }
}

int flag[N];
void run(){
    if(cst!=-1e9){
        for(auto &u : seq) val[u]=1.0*cst*p[u].a+p[u].b;
        return;
    }
    sort(seq.begin(),seq.end(),cmp);
    for(auto &u : seq) if(p[u].a<0) p[u].a=-p[u].a,p[u].b=-p[u].b,flag[u]=-1;
    int i=0;
    while(i<sz(seq)&&p[seq[i]].a==0) i++;
    double po,mi=1e9,suma=0,sumb=0;
    for(auto &u : seq) suma-=p[u].a,sumb-=p[u].b;
    for(;i<sz(seq);i++){
        node u=p[seq[i]];
        sumb+=2*u.b; suma+=2*u.a;
        double p=-1.0*u.b/u.a, now=sumb+suma*p;
        if(now<mi) mi=now,po=p;
        // out(p); outln(now);
    }
    for(auto &u : seq) val[u]=(po*p[u].a+p[u].b)*flag[u];    
}

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) flag[i]=1;
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        v[x].push_back(mk(y,z)); v[y].push_back(mk(x,z));
    }
    for(int i=1;i<=n;i++) if(!vis[i]){
        cst=-1e9;
        p[i]={1,0}; seq.clear();
        dfs(i); run();
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%.1lf ",val[i]);
    return 0;
}
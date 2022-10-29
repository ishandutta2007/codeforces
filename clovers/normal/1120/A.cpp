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
const int N=500005;
int n,k,m,s,t[N],cnt=0;
int vis[N],a[N],b[N],lim[N];
void print(){
    vector<int> v;
    for(int i=1;i<=n;i++) if(!vis[i]) v.push_back(i);
    printf("%d\n",sz(v));
    for(auto &u : v) printf("%d ",u);
    exit(0);
}

void run(int l,int r){
    out(l); outln(r);
    memset(t,0,sizeof(t));
    int now=0;
    for(int i=l;i<=r;i++){
        if(t[a[i]]>=lim[a[i]]) continue;
        vis[i]=1; t[a[i]]++;
        if(t[a[i]]==lim[a[i]]) now++;
    }
    int rest=k-s;
    for(int i=l;i<=r;i++) if(!vis[i]){
        if(rest) rest--,vis[i]=1;
    }
    m--; if(!m) print();
    for(int i=l-k;i>=1;i-=k){
        for(int j=i;j<i+k;j++) vis[j]=1;
        m--; if(!m) print();
    }
    for(int i=r+k;i<=n;i+=k){
        for(int j=i-k+1;j<=i;j++) vis[j]=1;
        m--; if(!m) print();
    }
}

int main()
{
    n=read(); k=read(); m=read(); s=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1,x;i<=s;i++) x=read(),cnt+=(!lim[x]),lim[x]++;
    int ans=0,now=0;
    for(int l=1,r=0;l+k-1<=n;l++){
        while(r<n&&now<cnt){
            r++;
            t[a[r]]++;
            if(t[a[r]]==lim[a[r]]) now++;
        }
        if(now<cnt) break;
        int rr=max(r,l+k-1);
        if(1+(l-1)/k+(n-rr)/k>=m) run(l,rr); 
        if(t[a[l]]==lim[a[l]]) now--;
        t[a[l]]--;
    }
    puts("-1");
    return 0;
}
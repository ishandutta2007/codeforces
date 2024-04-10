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
const int N=200005;
int n,a[N],pos[N],num[N],vis[N],b[N],rt,top=0;
vector<pii> v;
vector<vector<int> > seq;
void Swap(int x,int y){
    swap(pos[a[x]],pos[a[y]]);
    swap(a[x],a[y]);
    num[a[x]]++; num[a[y]]++;
    v.push_back(mk(x,y));
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),pos[a[i]]=i;
    for(int i=1;i<=n;i++){
        if(a[i]==i||vis[i]) continue;
        vector<int> t; t.clear();
        int x=a[i]; t.push_back(i); vis[i]=1;
        while(x!=i) vis[x]=1,t.push_back(x),x=a[x];
        seq.push_back(t);
    }
    for(int i=0;i<sz(seq)-1;i+=2){
        vector<int> t1=seq[i],t2=seq[i+1];
        for(auto &u : t1) Swap(u,t2[0]);
        for(int j=1;j<sz(t2);j++) Swap(t1[0],t2[j]);
        Swap(t1[0],t2[0]);
    }
    if(sz(seq)%2==1){
        int rt=-1;
        for(int i=1;i<=n;i++) if(a[i]==i) rt=i;
        vector<int> t=seq.back();
        if(rt==-1){
            for(auto &u : t) b[++top]=u;
            for(int i=2;i<=n-1;i++) Swap(b[1],b[i]);
            Swap(b[2],b[n]); Swap(b[n],b[1]);
            Swap(b[1],b[2]);
        }
        else{
            for(auto &u : t) Swap(rt,u);
            Swap(rt,t[0]);
        }
    }
    assert(sz(v)<=n+1);
    for(int i=1;i<=n;i++) assert(a[i]==i&&num[i]%2==0);
    printf("%d\n",sz(v));
    for(auto &u : v) printf("%d %d\n",u.first,u.second);
    return 0;
}
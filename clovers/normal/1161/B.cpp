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
const int M=1005;
const int MOD1=77878877;
const int MOD2=77877997;
const int B=73;
pii pw[N];
pii operator + (pii A,pii B){return mk((A.first+B.first)%MOD1,(A.second+B.second)%MOD2);}
pii operator - (pii A,pii B){return mk((A.first-B.first+MOD1)%MOD1,(A.second-B.second+MOD2)%MOD2);}
pii operator * (pii A,pii B){return mk(1ll*A.first*B.first%MOD1,1ll*A.second*B.second%MOD2);}
pii operator * (pii A,int x){return mk(1ll*A.first*x%MOD1,1ll*A.second*x%MOD2);}
pii a[N];
int n,m;
void add_edge(int x,int y){
    y-=x; if(y<0) y+=n;
    a[x]=a[x]+pw[y];
}
int nxt[N];
int Kmp(){
    for(int i=1;i<n;i++){
        int j=nxt[i];
        while(j&&a[i+1]!=a[j+1]) j=nxt[j];
        if(a[i+1]==a[j+1]) j++;
        nxt[i+1]=j;
    }
    return n-nxt[n];
}

int main()
{
    n=read(); m=read();
    pw[0]=mk(1,1);
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]*B;
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        add_edge(x,y); add_edge(y,x);
    }
    int tmp=Kmp();
    outln(tmp);
    puts(tmp!=n&&n%tmp==0 ? "Yes" : "No");
    return 0;
}
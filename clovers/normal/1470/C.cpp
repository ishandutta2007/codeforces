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
typedef unsigned long long ull;
const int N=100005;
int K=1;
int Rand(){return rand()&32767;}
int ran(int l,int r){
    ull ret=((ull)Rand()<<15)+Rand();
    return ret%(r-l+1)+l;
}
int n,k,P,pos; ll a[N],b[N],num;
ll ask(int x){
    printf("? %d\n",x);
    fflush(stdout);
    ll ret=read();
    return ret;
}
int vis[N];

int main()
{
    srand(time(NULL));
    n=read(); k=read();
    for(int i=1;i<=n;i++) a[i]=k;
    ask(1);
    int rnd=0;
    for(int i=1;i<=n;i++) vis[i]=1;
    int tot=0;
    while(true){
        rnd++;
        b[1]=(a[n]+1)/2+a[2]/2;
        b[2]=a[3]/2+a[1]; b[n]=(a[n-1]+1)/2;
        for(int i=3;i<n;i++) b[i]=(a[i-1]+1)/2+a[i+1]/2;
        for(int i=1;i<=n;i++) a[i]=b[i];
        int top=0; for(int i=K;i<=n;i++) b[i]=a[++top];
        for(int i=1;i<K;i++) b[i]=a[++top];
        if(!tot) pos=ran(1,n);
        else if(tot&1) pos=P-tot/2-1,tot++;
        else pos=P+tot/2,tot++;
        while(pos>n) pos-=n; while(pos<=0) pos+=n;
        outln(b[pos]);
        num=ask(pos);
        if(!tot&&num!=k) tot++,P=pos;
        for(int i=1;i<=n;i++) if(a[i]!=num){
            int p=pos-i+1; if(p<=0) p+=n;
            vis[p]=0;
        }
        int cnt=0,ret=0;
        for(int i=1;i<=n;i++) if(vis[i]){
            cnt++,ret=i;
        } 
        if(cnt==1){
            printf("! %d\n",ret);
            fflush(stdout); return 0;
        }
    }
    return 0;
}
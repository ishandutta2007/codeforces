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
int n,a[N],b[N],c[N],p[N];
ll ret[31][2];
ll ans=0,X=0;
void solve(int l,int r,int bit){
    if(l>=r||bit==-1) return;
    int topb=0,topc=0; ll tmp0=0,tmp1=0;
    for(int i=l;i<=r;i++){
        if(a[i]>>bit&1) c[++topc]=i;
        else b[++topb]=i;
    }
    int ib=1,ic=1,top=l-1;
    while(ib<=topb||ic<=topc){
        if(ib<=topb&&(ic>topc||b[ib]<c[ic])) ib++,tmp0+=ic-1;
        else ic++,tmp1+=ib-1;
    }
    ret[bit][0]+=tmp0; ret[bit][1]+=tmp1; 
    for(int i=1;i<=topb;i++) p[++top]=a[b[i]]; int mid=top;
    for(int i=1;i<=topc;i++) p[++top]=a[c[i]];
    for(int i=l;i<=r;i++) a[i]=p[i];
    solve(l,mid,bit-1); solve(mid+1,r,bit-1);
}

int main()
{
    n=read(); for(int i=1;i<=n;i++) a[i]=read();
    solve(1,n,30);
    for(int i=0;i<=30;i++){
        if(ret[i][0]<=ret[i][1]) ans+=ret[i][0];
        else ans+=ret[i][1],X|=(1<<i);
    }
    cout<<ans<<" "<<X<<endl;
    return 0;
}
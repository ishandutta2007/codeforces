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
int p[N],n,q,f[N],s[N],sum[N],g[N];
int calc(int l,int r){
    int tmp1=sub(sum[r-1],sum[l-1]);
    int tmp2=sub(g[r-1],g[l-1]);
    Sub(tmp1,mul(l-1,tmp2));
    Mul(tmp1,qpow(s[l-1],MOD-2));
    int P=mul(s[r-1],qpow(s[l-1],MOD-2));
    int ret=add(r-l,mul(tmp1,qpow(P,MOD-2)));
    return ret;
}
set<int> st;
int a[N];

int main()
{
    n=read(); q=read(); 
    for(int i=1;i<=n;i++) p[i]=mul(read(),qpow(100,MOD-2));
    s[0]=1; for(int i=1;i<=n;i++) s[i]=mul(s[i-1],p[i]);
    for(int i=1;i<=n;i++) f[i]=mul(s[i-1],MOD+1-p[i]);
    for(int i=1;i<=n;i++) sum[i]=add(sum[i-1],mul(i,f[i]));
    for(int i=1;i<=n;i++) g[i]=add(g[i-1],f[i]);
    int ans=calc(1,n+1); st.insert(1); st.insert(n+1);
    a[1]=1;
    while(q--){
        int x=read();
        if(a[x]){
            auto it=st.lower_bound(x);
            auto it2=it,it3=it;
            it2--; it3++;
            Sub(ans,calc(*it2,*it));
            Sub(ans,calc(*it,*it3));
            Add(ans,calc(*it2,*it3));
            st.erase(it); a[x]=0;
        }
        else{
            auto it1=st.lower_bound(x);
            auto it2=it1; it2--;
            Sub(ans,calc(*it2,*it1));
            Add(ans,calc(*it2,x));
            Add(ans,calc(x,*it1));
            st.insert(x); a[x]=1;
        }
        printf("%d\n",ans);
    }   
    return 0;
}
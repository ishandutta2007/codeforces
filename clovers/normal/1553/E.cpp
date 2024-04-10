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
int T,n,m,a[N],vis[N],c[N];
int p[N];

int main()
{
    T=read();
    while(T--){
        vector<int> v;
        n=read(); m=read();
        for(int i=0;i<n;i++) a[i]=read()-1,c[i]=0;
        for(int i=0;i<n;i++) c[(i-a[i]+n)%n]++;
        for(int num=0;num<n;num++) if(c[num]>=n-m-m){
            for(int i=0;i<n;i++) p[(i-num+n)%n]=a[i];//!!
            int tot=n; for(int i=0;i<n;i++) vis[i]=0;
            for(int i=0;i<n;i++) if(!vis[i]){
                tot--; int x=i;
                while(!vis[x]) vis[x]=1,x=p[x];
            }
            if(tot<=m) v.push_back(num);
        }
        printf("%d ",sz(v));
        for(int i=0;i<sz(v);i++) printf("%d ",v[i]); puts("");
    }
    return 0;
}
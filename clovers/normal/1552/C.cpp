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
const ll INF=(ll)2e18;
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
const int N=205;
int n,k,vis[N],x[N],y[N];

int main()
{
    int T=read();
    while(T--){
        memset(vis,0,sizeof(vis));
        n=read(); k=read();
        for(int i=1;i<=k;i++){
            x[i]=read(),y[i]=read(),vis[x[i]]=1,vis[y[i]]=1;
            if(x[i]>y[i]) swap(x[i],y[i]); 
        }
        int ans=(n-k)*(n-k-1)/2;
        for(int i=1;i<=k;i++){
            int num1=0,num2=0;
            int now=x[i];
            while(now!=y[i]){
                num1+=(!vis[now]);
                now++;
                if(now>n+n) now-=n*2;
            }
            while(now!=x[i]){
                num2+=(!vis[now]);
                now++;
                if(now>n+n) now-=n*2;
            }
            ans+=min(num1,num2);
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++) ans+=(x[i]<x[j]&&x[j]<y[i]&&y[i]<y[j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
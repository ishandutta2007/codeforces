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
const int M=1200000;
int n,m;
ll f[M],cnt[M],t[M];
char s[25][N];
void FWT(ll *a,int len,int flag){
    for(int h=1;h<len;h<<=1){
        for(int i=0;i<len;i+=(h<<1)){
            for(int j=i;j<i+h;j++){
                ll tmp1=a[j],tmp2=a[j+h];
                a[j]=tmp1+tmp2; a[j+h]=tmp1-tmp2;
            }
        }
    }
    if(flag==-1){
        for(int i=0;i<len;i++) a[i]/=len;
    }
}

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int j=1;j<=m;j++){
        int S=0;
        for(int i=1;i<=n;i++) if(s[i][j]=='1') S|=(1<<i-1);
        t[S]++;
    }
    int full=(1<<n)-1;
    for(int i=1;i<=full;i++){
        int to=i-(i&(-i));
        cnt[i]=cnt[to]+1; f[i]=min(cnt[i],n-cnt[i]);
    }
    FWT(f,full+1,1); FWT(t,full+1,1);
    for(int i=0;i<=full;i++) f[i]*=t[i];
    FWT(f,full+1,-1);
    int ans=inf;
    for(int i=0;i<=full;i++) checkmin(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}
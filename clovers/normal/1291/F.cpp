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
const int N=2005;
int n,k,vis[N],cnt=0;
int q[N*N],f=1,b=0;
void ask(int x){
    if(vis[x]) return;
    cnt++;
    printf("? %d\n",x); fflush(stdout);
    char s[2]; scanf("%s",s);
    if(s[0]=='Y') vis[x]=1;
    q[++b]=x;
    if(b-f==k) f++;
}
void Reset(){puts("R"); fflush(stdout); b=f; f++;}

int main()
{
    n=read(); k=read();
    if(n==k) for(int i=1;i<=n;i++) ask(i);
    for(int h=k;h<n;h+=k){
        for(int i=1;i<=h;i+=k){
            Reset();
            for(int p=i;p<=n;p+=h){
                for(int j=p;j<p+k;j++) ask(j);
            }
            Reset();
            for(int p=i;p<=n;p+=h){
                for(int j=p+k-1;j>=p;j--) ask(j);
            }
        }
    }
    out(cnt); outln(2*n*n/k);
    int ans=0;
    for(int i=1;i<=n;i++) ans+=(!vis[i]);
    printf("! %d\n",ans); fflush(stdout);
    return 0;
}
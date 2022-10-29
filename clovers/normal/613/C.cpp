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
int n,a[N],posl[N],posr[N],b[N],sum=0;
char s[N];

int main()
{
    n=read(); for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
    if(n==1){
        cout<<sum<<endl;
        for(int i=1;i<=sum;i++) printf("a");
        return 0;
    }
    int g=a[1],bl=0;
    for(int i=1;i<=n;i++) bl+=(a[i]&1);
    if(bl>=2){
        puts("0");
        for(int i=1;i<=n;i++){
            while(a[i]--) printf("%c",i+'a'-1);
        }
        return 0;
    }
    for(int i=2;i<=n;i++) g=__gcd(g,a[i]);
    bl=0;
    for(int i=1;i<=n;i++) bl+=((a[i]/g)&1);
    if(bl>=2) g/=2,bl=0;
    printf("%d\n",(bl==0 ? g*2 : g));
    sum/=g;
    for(int i=1;i<=n;i++) a[i]/=g;
    int pos=-1,l=1,r=sum;
    for(int i=1;i<=n;i++){
        if(a[i]%2==0) while(a[i]){
            s[l++]=i+'a'-1; s[r--]=i+'a'-1;
            a[i]-=2;
        }
        else pos=i;
    }
    if(pos!=-1) for(int i=l;i<=r;i++) s[i]=pos+'a'-1;
    for(int i=sum+1;i<=sum*g;i++){
        int j=(i-1)%sum+1;
        s[i]=s[j];
    }
    for(int i=1;i<=sum*g;i++) printf("%c",s[i]);
    return 0;
}
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
int T,n; char s[N];
int a[N],b[N],topa=0,topb=0;
int id[N];

int main()
{
    T=read();
    while(T--){
        n=read(); topa=0; topb=0;
        scanf("%s",s+1);
        int pre=0;
        for(int i=1;i<=n;i++) id[i]=1;
        for(int i=1;i<n;i++){
            if(s[i]>s[i+1]){
                int l=i;
                while(l>=2&&s[l-1]>s[i+1]&&id[l-1]==1) l--;
                if(!pre) pre=l;
                for(int j=i;j>=l;j--) id[j]=2;
            } 
        }
        for(int i=n;i>=1;i--){
            if(id[i]==1&&pre&&s[i]>s[pre]) id[i]=2;
        }
        for(int i=1;i<=n;i++){
            if(id[i]==1) a[++topa]=s[i]-'0';
            else b[++topb]=s[i]-'0';
        }
        for(int i=1;i<=topb;i++) a[++topa]=b[i];
        int flag=1;
        for(int i=2;i<=topa;i++) if(a[i]<a[i-1]) flag=0;
        if(flag==0) puts("-");
        else{
            for(int i=1;i<=n;i++) printf("%d",id[i]);
            puts("");
        }
    }
    return 0;
}
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
int T,n=10;
int a[N]; char s[N];
int calc(){
    int sum1=0,sum2=0;
    for(int i=1;i<=n;i++){
        if(i&1) sum1+=a[i];
        else sum2+=a[i];
        int rest1=(n-i)/2,rest2=(n-i+1)/2;
        if(sum2+rest2<sum1||sum1+rest1<sum2) return i;
    }
    return 10;
}

int main()
{
    T=read();
    while(T--){
        scanf("%s",s+1);
        vector<int> v;
        for(int i=1;i<=n;i++){
            if(s[i]=='?') v.push_back(i);
            else a[i]=s[i]-'0';
        }
        int ans=inf;
        int full=(1<<sz(v));
        for(int S=0;S<full;S++){
            for(int i=0;i<sz(v);i++) if(S>>i&1) a[v[i]]=1; else a[v[i]]=0;
            checkmin(ans,calc());
        }
        printf("%d\n",ans);
    }
    return 0;
}
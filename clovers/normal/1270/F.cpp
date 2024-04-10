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
const int B=200;
const int M=40000000;
int n,sum[N]; char s[N];
int t[M*2+5],nxt[N];
ll ans=0;

int main()
{
    scanf("%s",s+1); n=strlen(s+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+s[i]-'0';
    int now=n+1;
    for(int i=n;i>=1;i--){
        nxt[i]=now; 
        if(s[i]=='1') now=i;
    }
    for(int i=1;i<=n;i++){
        int now=i;
        for(int k=1;k*B<=n;k++){//num of 1
            if(k==1){
                if(s[i]!='1') now=nxt[now];
            }
            else now=nxt[now];
            if(now==n+1) break;
            int l=now-i+1,r=nxt[now]-i;
            ans+=max(0,r/k-B)-max(0,(l-1)/k-B);
        }
    }
    for(int k=1;k<=B;k++){//times
        memset(sum,0,sizeof(sum));
        t[M]++;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]-1;
            if(s[i]=='1') sum[i]+=k;
            ans+=t[M+sum[i]]; t[M+sum[i]]++;
        }
        t[M]--;
        for(int i=1;i<=n;i++) t[M+sum[i]]--;
    }
    cout<<ans<<endl;
    return 0;
}
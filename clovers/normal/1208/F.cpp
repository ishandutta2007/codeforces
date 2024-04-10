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
const int N=2200005;
pii dp[N];
pii merge(pii A,pii B){
    int t[4];
    t[0]=A.first; t[1]=A.second; t[2]=B.first; t[3]=B.second;
    sort(t,t+4);
    return mk(t[3],t[2]);
}
int n,a[N],m=(1<<21);
void FWT(pii *a,int len){
    for(int h=1;h<len;h<<=1){
        for(int i=0;i<len;i+=(h<<1)){
            for(int j=i;j<i+h;j++) a[j]=merge(a[j],a[j+h]);
        }
    }
}

int main()
{
    n=read(); 
    for(int i=0;i<m;i++) dp[i]=mk(0,0);
    for(int i=1;i<=n;i++){
        a[i]=read();
        dp[a[i]].second=dp[a[i]].first;
        dp[a[i]].first=i;
    }
    FWT(dp,m);
    int ans=0;
    for(int i=1;i<=n-2;i++){
        int now=0,ret=0;
        for(int j=20;j>=0;j--){
            int to=now|(1<<j);
            if(a[i]>>j&1){
                ret|=(1<<j);
                continue;
            }
            if(dp[to].second>i) now=to,ret|=(1<<j);
        } 
        checkmax(ans,ret);
    }
    cout<<ans<<endl;
    return 0;
}
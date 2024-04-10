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
const int N=10;
int T,n,a[N];

int main()
{
    T=read();
    while(T--){
        n=read();
        for(int i=0;i<n;i++) a[i]=read();
        int flag=0;
        int full=(1<<n)-1;
        for(int S1=1;S1<=full;S1++){
            int rest=(full^S1);
            int sum1=0;
            for(int i=0;i<n;i++) if(S1>>i&1) sum1+=_abs(a[i]);
            flag|=(sum1==0);
            for(int S2=rest;S2;S2=((S2-1)&rest)){
                int sum2=0;
                for(int i=0;i<n;i++){
                    if(S2>>i&1) sum2+=_abs(a[i]);
                }
                flag|=(sum1==sum2);
            }
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
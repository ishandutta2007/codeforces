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
int n,m,L=1,R,rev=0,a[N];
namespace BIT{
    int a[N];
    int lowbit(int x){return x&(-x);}
    void update(int x,int val){for(int i=x;i<=n;i+=lowbit(i)) a[i]+=val;}
    int query(int x){
        int ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=a[i];
        return ret;
    }
}

int main()
{
    n=read(); m=read(); R=n;
    for(int i=1;i<=n;i++) a[i]=1,BIT::update(i,1);
    while(m--){
        int opt=read();
        if(opt==1){
            int sz=R-L+1,len=read();
            if(rev==0){
                if(len*2<=sz){
                    for(int i=L;i<L+len;i++){
                        int to=L*2+2*len-1-i;
                        a[to]+=a[i]; 
                        BIT::update(to,a[i]); BIT::update(i,-a[i]);
                        a[i]=0;
                    }
                    L+=len;
                }
                else{
                    rev^=1; len=sz-len;
                    for(int i=R;i>R-len;i--){
                        int to=R*2-2*len+1-i;
                        a[to]+=a[i];
                        BIT::update(to,a[i]); BIT::update(i,-a[i]);
                        a[i]=0;
                    }
                    R-=len;
                }
            }
            else{
                if(len*2<=sz){
                    for(int i=R;i>R-len;i--){
                        int to=R*2-2*len+1-i;
                        a[to]+=a[i];
                        BIT::update(to,a[i]); BIT::update(i,-a[i]);
                        a[i]=0;
                    }
                    R-=len;
                }
                else{
                    rev^=1; len=sz-len;
                    for(int i=L;i<L+len;i++){
                        int to=L*2+2*len-1-i;
                        a[to]+=a[i]; 
                        BIT::update(to,a[i]); BIT::update(i,-a[i]);
                        a[i]=0;
                    }
                    L+=len;
                }
            }
        }
        else{
            int l=read()+L-1,r=read()+L-1;
            if(rev==1){
                l=L-1+R-l; r=L-1+R-r;
                swap(l,r);
            }
            printf("%d\n",BIT::query(r)-BIT::query(l));
        }
        //for(int i=1;i<=n;i++) printf("%d ",a[i]); cout<<endl;
    }
    return 0;
}
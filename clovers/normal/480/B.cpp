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
map<int,int> mp;
int n,x,y,a[N],l;
int blx=0,bly=0;

int main()
{
    n=read(); l=read(); x=read(); y=read();
    for(int i=1;i<=n;i++) a[i]=read(),mp[a[i]]=1;
    for(int i=2;i<=n;i++){
        if(mp.count(a[i]-x)) blx=1;
        if(mp.count(a[i]-y)) bly=1;
    }
    if(blx&&bly){puts("0"); return 0;}
    if(blx||bly){
        puts("1");
        if(!blx) printf("%d\n",x);
        else printf("%d\n",y);
        return 0;
    }
    for(int i=1;i<=n;i++){
        int pos=a[i]+x;
        if(pos>=0&&pos<=l){
            if(mp.count(pos+y)||mp.count(pos-y)){
                puts("1");
                printf("%d\n",pos);
                return 0;
            }
        }
        pos=a[i]-x;
        if(pos>=0&&pos<=l){
            if(mp.count(pos+y)||mp.count(pos-y)){
                puts("1");
                printf("%d\n",pos);
                return 0;
            }
        }
    }
    puts("2");
    printf("%d %d\n",min(x,y),max(x,y));
    return 0;
}
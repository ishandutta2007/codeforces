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
const int N=50005;
int T,n,a[N],bl[N];
struct node{
    int i,j,x;
};
vector<node> ans;
void F(int i,int j,int x){
    a[i]-=x*i,a[j]+=x*i;
    assert(a[i]>=0&&a[j]>=0);
    ans.push_back({i,j,x});
}

int main()
{
    T=read();
    while(T--){
        int sum=0;
        n=read(); for(int i=1;i<=n;i++) a[i]=read(),bl[i]=0,sum+=a[i];
        ans.clear();
        if(sum%n){
            puts("-1");
            continue;
        }
        sum/=n;
        for(int i=2;i<=n;i++){
            int rest=(i-a[i]%i)%i;
            if(rest) F(1,i,rest);
            F(i,1,a[i]/i);
        }
        for(int i=1;i<=n;i++) if(a[i]<sum) F(1,i,sum-a[i]);
        for(int i=1;i<=n;i++) assert(a[i]==sum);
        printf("%d\n",sz(ans));
        for(auto &u : ans) printf("%d %d %d\n",u.i,u.j,u.x);
    }
    return 0;
}
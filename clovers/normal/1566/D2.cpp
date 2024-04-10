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
const int N=305;
int n,m,a[N*N],val[N*N],pos[N][N],TT;
vector<int> v[N*N];
int idx(int x,int y){return (x-1)*m+y;}
struct BIT{
    int a[N*N];
    int lowbit(int x){return x&(-x);}
    void update(int x,int val){
        for(int i=x;i<=n*m;i+=lowbit(i)) a[i]+=val;
    }
    int query(int x){
        int ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=a[i];
        return ret; 
    }
}T[N];

int main()
{
    TT=read();
    while(TT--){
        n=read(); m=read();
        for(int i=1;i<=n*m;i++) a[i]=read(),val[i]=a[i],v[i].clear();
        sort(val+1,val+n*m+1);
        int top=unique(val+1,val+n*m+1)-val-1;
        for(int i=1;i<=n*m;i++){
            a[i]=lower_bound(val+1,val+top+1,a[i])-val;
            v[a[i]].push_back(i);
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) pos[i][j]=0;
        sort(a+1,a+n*m+1);
        ll sum=0;
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++){
                int num=a[idx(i,j)];
                if(a[idx(i,m)]==num) continue;
                pos[i][j]=v[num].back(); v[num].pop_back();
            }
        }
        for(int i=1;i<=top;i++) reverse(v[i].begin(),v[i].end());
        for(int j=m;j>=1;j--){
            for(int i=1;i<=n;i++) if(!pos[i][j]){
                int num=a[idx(i,j)];
                if(a[idx(i,1)]==num) continue;
                pos[i][j]=v[num].back(); v[num].pop_back();
            }
        }
        for(int j=m;j>=1;j--){
            for(int i=1;i<=n;i++) if(!pos[i][j]){
                int num=a[idx(i,j)];
                pos[i][j]=v[num].back(); v[num].pop_back();
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum+=T[i].query(pos[i][j]);
                T[i].update(pos[i][j],1);
            }
            for(int j=1;j<=m;j++) T[i].update(pos[i][j],-1);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
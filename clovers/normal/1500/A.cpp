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
const int N=5000001;
int n,a[5001];
int vis[N],cnt[N];

void find(int x,int y){
    for(int i=1;i<=n;i++) if(i!=x&&i!=y){
        for(int j=i+1;j<=n;j++) if(j!=x&&j!=y){
            if(a[i]+a[j]==a[x]+a[y]){
                puts("YES");
                printf("%d %d %d %d\n",i,j,x,y);
                exit(0);
            }
        }
    }
    exit(0);
}

int main()
{
    srand(time(NULL));
    n=min(read(),5000);
    for(int i=1;i<=n;i++) a[i]=read(),cnt[a[i]]++;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++) vis[a[i]+a[j]]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            //out(i); out(j); out(vis[a[i]+a[j]]);
            if(a[i]!=a[j]){
                if(cnt[a[i]]>=2&&cnt[a[j]]>=2) find(i,j);
                if(vis[a[i]+a[j]]>cnt[a[i]]*cnt[a[j]]) find(i,j);
                //outln(cnt[a[i]]*cnt[a[j]]);
            }
            else{
                if(cnt[a[i]]>=4) find(i,j);
                if(vis[a[i]+a[j]]>cnt[a[i]]*(cnt[a[i]]-1)/2) find(i,j);
                // outln(cnt[a[i]]*(cnt[a[i]]-1)/2);
            }
        }
    }
    puts("NO");
    return 0;
}
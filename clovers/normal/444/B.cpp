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
int a[N],b[N],id[N],n; ll d,x;
long long getNextX(){
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d) b[i] = 1;
        else b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

bool cmp(int x,int y){return a[x]>a[y];}
int ans[N];
vector<int> v;

int main()
{
    n=read(); d=read(); x=read();
    initAB();
    for(int i=0;i<n;i++) id[i]=i;
    sort(id,id+n,cmp);
    for(int i=0;i<n;i++) if(b[i]) v.push_back(i);
    for(int i=0;i<n;i++){
        for(int j=0;j<min(n,300);j++){
            if(id[j]<=i&&b[i-id[j]]){ans[i]=a[id[j]]; break;}
        }
        if(!ans[i]){
            for(auto &u : v){
                if(u>i) break;
                checkmax(ans[i],a[i-u]);
            }
        }
    }
    for(int i=0;i<n;i++) printf("%d\n",ans[i]);
    return 0;
}
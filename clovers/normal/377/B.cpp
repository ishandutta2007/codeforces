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
int n,m,S;
pii b[N];
struct node{
    int abi,cost,id;
    bool operator < (const node &rhs) const{
        return cost>rhs.cost;
    }
}a[N];
bool cmp(node A,node B){return A.abi>B.abi;}
priority_queue<node> Q;
int bel[N],tmp[N];
bool check(int mid){
    while(!Q.empty()) Q.pop();
    ll sum=0; 
    for(int i=1,j=0;i<=m;i++){
        while(j!=n&&a[j+1].abi>=b[i].first) Q.push(a[j+1]),j++;
        if((i-1)%mid==0){
            if(Q.empty()) return 0;
            node u=Q.top(); Q.pop(); sum+=u.cost; 
            for(int k=i;k<=min(m,i+mid-1);k++){
                tmp[b[k].second]=u.id;
            }
        }
    }
    if(sum>S) return 0;
    for(int i=1;i<=m;i++) bel[i]=tmp[i];
    return 1;
}

int main()
{
    n=read(); m=read(); S=read();
    for(int i=1;i<=m;i++) b[i].first=read(),b[i].second=i;
    sort(b+1,b+m+1); reverse(b+1,b+m+1);
    for(int i=1;i<=n;i++) a[i].id=i;
    for(int i=1;i<=n;i++) a[i].abi=read();
    for(int i=1;i<=n;i++) a[i].cost=read();
    sort(a+1,a+n+1,cmp);
    if(a[1].abi<b[1].first){puts("NO"); return 0;}
    int l=1,r=m,mid,best=-1;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) r=mid-1,best=mid;
        else l=mid+1;
    }
    if(best==-1){puts("NO"); return 0;}
    puts("YES");
    for(int i=1;i<=m;i++) printf("%d ",bel[i]);
    puts("");
    return 0;
}
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
struct node{int x,y,z;};
vector<node> ans;
int n,a[N],vis[1<<13]; node pre[1<<13];
void opt(int x,int y,int z){
    a[x]^=1; a[y]^=1; a[z]^=1;
    ans.push_back({x,y,z});
}
void opt2(int x,int y,int z){
    a[x+1]^=1; a[y+1]^=1; a[z+1]^=1;
    ans.push_back({x+1,y+1,z+1});
}

bool bfs(int T){
    queue<int> q; q.push(0); vis[0]=1;
    while(!q.empty()){
        int S=q.front(); q.pop();
        if(S==T){
            while(S){
                node now=pre[S];
                opt(now.x+1,now.y+1,now.z+1);
                S^=(1<<now.x); S^=(1<<now.y); S^=(1<<now.z);
            }
            return 1;
        }
        for(int x=0;x<n;x++){
            for(int z=x+2;z<n;z+=2){
                int y=(x+z)>>1;
                int toS=(((S^(1<<x))^(1<<y))^(1<<z));
                if(!vis[toS]) q.push(toS),vis[toS]=1,pre[toS]={x,y,z};
            }
        }
    }
    return 0;
}

int main()
{
    n=read(); for(int i=1;i<=n;i++) a[i]=read();
    int lim=n/3+12,m=n;
    while(n>=14){
        if(!a[n]){n--; continue;}
        if(!a[n-1]){
            if(!a[n-2]) opt(n-6,n-3,n);
            else opt(n-4,n-2,n);
            n-=3; continue;
        }
        if(a[n-1]&&a[n-2]){opt(n-2,n-1,n); n-=3; continue;}
        if(a[n-3]&&a[n-4]&&a[n-5]){
            opt(n-5,n-3,n-1); opt(n-8,n-4,n);
        }
        else{
            int x=n;
            for(int i=n-3;i>=n-5;i--) if(a[i]){
                opt(i*2-x,i,x); x--;
            }
            if(x==n) opt(n-12,n-6,n);
            if(x>=n-1) opt(n-11,n-6,n-1);
        }
        n-=6;
    }
    int S=0; for(int i=1;i<=n;i++) if(a[i]) S|=(1<<i-1);
    if(!bfs(S)){puts("NO"); return 0;}
    for(int i=1;i<=m;i++) assert(!a[i]);
    assert(sz(ans)<=lim);
    puts("YES"); printf("%d\n",sz(ans));
    for(auto &u : ans) printf("%d %d %d\n",u.x,u.y,u.z);
    return 0;
}
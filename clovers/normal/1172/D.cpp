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
const int N=1005;
int n,r[N],c[N],ir[N],ic[N];
struct node{
    int x,y,xx,yy;
};
vector<node> ans;

int main()
{
    n=read();
    for(int i=1;i<=n;i++) r[i]=read(),ir[r[i]]=i;
    for(int i=1;i<=n;i++) c[i]=read(),ic[c[i]]=i;
    for(int rnd=1;rnd<n;rnd++){
        int x=ir[rnd],y=ic[rnd];
        if(x==rnd&&y==rnd) continue;
        if(x==n&&y==n){
            ans.push_back({n,rnd,rnd,n});
            r[n]=r[rnd]; c[n]=c[rnd]; ir[r[n]]=n; ic[c[n]]=n;
        } 
        else if(x==n){
            ans.push_back({n,rnd,rnd,y});
            int rrnd=r[rnd],crnd=c[rnd];
            r[n]=rrnd; ir[r[n]]=n;
            c[y]=crnd; ic[c[y]]=y;
        }
        else if(y==n){
            ans.push_back({x,rnd,rnd,n});
            int crnd=c[rnd],rrnd=r[rnd];
            c[n]=crnd; ic[c[n]]=n;
            r[x]=rrnd; ir[r[x]]=x;
        }
        else{
            ans.push_back({x,rnd,rnd,n});
            ans.push_back({rnd,y,n,rnd});
            int rn=r[n],cn=c[n],rrnd=r[rnd],crnd=c[rnd];
            if(x!=rnd) r[x]=rn,ir[r[x]]=x,r[n]=rrnd,ir[r[n]]=n;
            if(y!=rnd) c[y]=cn,ic[c[y]]=y,c[n]=crnd,ic[c[n]]=n;
        }
    }
    cout<<sz(ans)<<endl;
    for(auto &u : ans){
        printf("%d %d %d %d\n",u.x,u.y,u.xx,u.yy);
    }
    return 0;
}
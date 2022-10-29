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
const ll INF=(ll)1e18;
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
const int N=300005;
#define int long long
int n,a[N],b[N],m;

struct node{
    int id,typ,val;
    bool operator < (const node &rhs) const{
        return val>rhs.val;
    }
};
priority_queue<node> Q;
int vis1[N],vis2[N],vis3[N];

void print(){
    for(int i=1;i<=n;i++){
        if(vis2[i]||(vis1[i]&&vis3[i])) printf("2");
        else if(vis1[i]) printf("1");
        else printf("0");
    }
    puts("");
}

void solve(){
    int ans=0;
    for(int i=1;i<=n;i++) Q.push({i,1,a[i]*2}),Q.push({i,2,b[i]});
    int cnt=0;
    while(cnt<m-1){
        node u=Q.top(); Q.pop();
        if(vis2[u.id]) continue;
        if(vis1[u.id]&&u.typ==2) continue;
        if(vis1[u.id]&&u.typ==1) continue;
        if(u.typ==2) ans+=u.val,cnt+=2;
        else ans+=u.val/2,cnt++;
        if(u.typ==1){
            vis1[u.id]=1;
            Q.push({u.id,3,(b[u.id]-a[u.id])*2});
        }
        else if(u.typ==2) vis2[u.id]=1;
        else vis3[u.id]=1;
    }
    if(cnt==m-1){
        int mi1=INF,mi2=INF,mx1=-INF,mx2=-INF,posmi1,posmi2,posmx1,posmx2;
        for(int i=1;i<=n;i++){
            if(vis1[i]&&!vis3[i]){
                if(mi1>b[i]-a[i]) posmi1=i,mi1=b[i]-a[i];
                if(mx2<a[i]) posmx2=i,mx2=a[i];
            }
            else if(!vis1[i]&&!vis2[i]){
                if(mi1>a[i]) mi1=a[i],posmi1=i;
                if(mi2>b[i]) mi2=b[i],posmi2=i;
            }
            if((vis1[i]&&vis3[i])||vis2[i]) 
                if(mx1<b[i]-a[i]) posmx1=i,mx1=b[i]-a[i];
        }
        ans+=min(mi1,min(mi2-mx1,mi2-mx2));
        if(mi1<mi2-mx1&&mi1<mi2-mx2){
            if(vis1[posmi1]) vis2[posmi1]=1;
            else vis1[posmi1]=1;
        }
        else if(mi2-mx2<mi2-mx1){
            vis2[posmi2]=1; vis1[posmx2]=0;
        }
        else vis2[posmi2]=1,vis2[posmx1]=vis3[posmx1]=0,vis1[posmx1]=1;
    }
    cout<<ans<<endl;
    print();
}

signed main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read(),b[i]=read();
    // if(n<=1000){
    //     solver1::main();
    //     return 0;
    // }
    solve();
    return 0;
}
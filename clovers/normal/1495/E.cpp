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
const int MOD=1e9+7;
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
const int N=5000005;
const int M=200005;
int n,m,p[M],k[M],b[M],w[M];
int a[N]; int t[N];
int Seed=0,Base=0;
int Rnd(){
    int ret=Seed;
    Seed=add(mul(Seed,Base),233);
    return ret;
}
void init(){
    p[0]=0;
    n=read(); m=read();
    for(int i=1;i<=m;i++) p[i]=read(),k[i]=read(),b[i]=read(),w[i]=read();
    for(int i=1;i<=m;i++){
        Seed=b[i],Base=w[i];
        for(int j=p[i-1]+1;j<=p[i];j++){
            t[j]=Rnd()%2+1;
            a[j]=Rnd()%k[i]+1;
        }
    }
    //for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
    //for(int i=1;i<=n;i++) cout<<t[i]<<" "; cout<<endl;
}
int bel[N],ans[N]; ll sum[N],s[N];
void solve(){
    a[1]--; ans[1]++;
    int tot=0;
    int flag=0;
    for(int i=2;i<=n;i++) if(t[i]!=t[i-1]) flag=1;
    memset(bel,-1,sizeof(bel));
    if(!flag) return;
    ll sum1=0,sum2=0;
    for(int i=1;i<=n;i++){
        if(bel[i]==-1){
            int x=i;
            while(t[x]==t[i]){
                bel[x]=tot,x++;
                if(x>n) x-=n;
            }
            x=i;
            while(t[x]==t[i]){
                bel[x]=tot,x--;
                if(x<=0) x+=n;
            } tot++;
        } sum[bel[i]]+=a[i];
    }
    sum[tot]=sum[0];
    //for(int i=1;i<=tot;i++) cout<<sum[i]<<" "; cout<<endl;
    ll now=0;
    for(int i=1;i<=tot;i++){
        if(i&1) now+=sum[i],sum1+=sum[i];
        else now-=sum[i],sum2+=sum[i];
        checkmax(now,0ll);
    }
    for(int i=1;i<=tot;i++){
        if(i&1){
            now+=sum[i];
        }
        else{
            ll tmp=min(now,sum[i]);
            s[i]=tmp;
            now-=tmp;
        }
    }
    // if(sum1<sum2){
    //     int x=2;
    //     while(true){
    //         if(s[x]!=sum[x]){s[x]++; break;}
    //         x+=2;
    //     }
    // }
    now=0;
    for(int i=1;i<=tot;i++){
        if(!(i&1)) now+=sum[i];
        else now-=sum[i];
        checkmax(now,0ll);
    }
    for(int i=1;i<=tot;i++){
        if(!(i&1)){
            now+=sum[i];
        }
        else{
            ll tmp=min(now,sum[i]);
            s[i]=tmp;
            now-=tmp;
        }
    }
    if(sum1>sum2){
        int x=1;
        while(true){
            if(s[x]!=sum[x]){s[x]++; break;}
            x+=2;
        }
    }
    //for(int i=1;i<=tot;i++) cout<<s[i]<<" "; cout<<endl;
    s[0]=s[tot];
    tot=0; memset(bel,-1,sizeof(bel));
    for(int i=1;i<=n;i++){
        int l,r;
        if(bel[i]==-1){
            int x=i;
            while(t[x]==t[i]){
                r=x;
                bel[x]=tot,x++;
                if(x>n) x-=n;
            } 
            x=i;
            while(t[x]==t[i]){
                l=x;
                bel[x]=tot,x--;
                if(x<=0) x+=n;
            } tot++;
        }
        while(s[bel[i]]){
            ll tmp=min(s[bel[i]],(ll)a[l]);
            ans[l]+=tmp; s[bel[i]]-=tmp; 
            l++; if(l>n) l-=n;
        }
    }
    //for(int i=1;i<=n;i++) cout<<ans[i]<<" "; cout<<endl;
}

int main()
{
    init();
    solve();
    ll ret=1;
    for(int i=1;i<=n;i++) ret=ret*((ans[i]^(1ll*i*i))%MOD+1)%MOD;
    cout<<ret<<endl;
    return 0;
}
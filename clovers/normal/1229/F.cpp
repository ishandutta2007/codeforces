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
#define int long long
const int N=35005;
int n,a[N],l[N],r[N];
ll ans=INF;
ll run(ll x){
    priority_queue<ll> L; priority_queue<ll,vector<ll>,greater<ll> > R;
    for(int i=1;i<=n+1;i++) L.push(x),R.push(x);
    ll movel=0,mover=0,ret=_abs(x);
    for(int i=2;i<=n;i++){
        movel+=r[i]-a[i]; mover+=r[i]-a[i];
        movel-=(r[i]-l[i]);
        if(movel+L.top()>=0){
            ll tmp=L.top(); L.pop(); ret+=movel+tmp;
            R.push(movel+tmp-mover); L.push(-movel); L.push(-movel);
        }
        else if(mover+R.top()<=0){
            ll tmp=R.top(); R.pop(); ret-=(mover+tmp);
            L.push(mover+tmp-movel); R.push(-mover); R.push(-mover);
        }
        else{L.push(-movel); R.push(-mover);}
    }
    ll ansr=a[1]+x-l[1],ansl=a[1]+x-r[1];
    if(!(R.top()+mover<ansl||L.top()+movel>ansr)) return ret;
    else if(R.top()+mover<ansl){
        R.push(INF);
        ll p=R.top()+mover,k=1; R.pop();
        while(true){
            ll now=R.top()+mover; R.pop();
            if(now>=ansl) return ret+(ansl-p)*k;
            ret+=(now-p)*k; p=now; k++;
        }
    }
    else{
        L.push(-INF);
        ll p=L.top()+movel,k=1; L.pop();
        while(true){
            ll now=L.top()+movel; L.pop();
            if(now<=ansr) return ret-(ansr-p)*k;
            ret-=(now-p)*k; p=now; k++;
        }
    }
    assert(0);
}

signed main()
{
    n=read();
    ll sum=0;
    for(int i=1;i<=n;i++) a[i]=read(),l[i]=read(),r[i]=read(),sum+=a[i];
    ll L=-sum,R=sum,mid1,mid2;
    while(L+5<=R){
        mid1=(L+L+R)/3,mid2=(L+R+R)/3;
        ll val1=run(mid1),val2=run(mid2);
        checkmin(ans,val1),checkmin(ans,val2);
        if(val1<val2) R=mid2; else L=mid1;
    }
    for(ll i=L;i<=R;i++) checkmin(ans,run(i));
    cout<<ans<<endl;
    return 0;
}
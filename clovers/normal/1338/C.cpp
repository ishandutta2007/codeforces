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
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
int Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
int Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
int Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline ll read(){
    ll x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
#define int long long
const int N=500005;
const int M=1005;
int T;

int calc(int x,int k){
    if(k==0) return 0;
    int r=x/(1ll<<(k-2)),d=x%(1ll<<(k-2));
    if(r==0) return calc(d,k-2);
    else if(r==1) return 3*(1ll<<(k-2))+calc(d,k-2);
    else if(r==2) return 1*(1ll<<(k-2))+calc(d,k-2);
    else if(r==3) return 2*(1ll<<(k-2))+calc(d,k-2);
}

void solve(int n){
    int k=0;
    while((1ll<<(k+2))<=n) k+=2;
    int delta=n-(1ll<<k)+1;
    //outln(delta);
    int r=delta%3,d=delta/3;
    int fir=(1ll<<k)+d;
    int pos=calc((delta-1)/3,k);
    int thi=(1ll<<k)*3+pos;
    int sec=fir^thi;
    if(r==0) printf("%lld\n",thi);
    else if(r==1) printf("%lld\n",fir);
    else if(r==2) printf("%lld\n",sec);
}

signed main()
{
    /*for(int i=1;i<=100;i++){
        int tmp=0;
        for(int j=1;j<=10000;j++) if(!bl[j]) {tmp=j; break;}
        int tmp2=0;
        bl[tmp]=1;
        for(int j=1;j<=200000;j++) if(!bl[j]&&!bl[tmp^j]){tmp2=j; break;}
        ans[++n]=tmp; ans[++n]=tmp2; ans[++n]=tmp^tmp2;
        bl[tmp2]=1; bl[tmp^tmp2]=1;
    }
    for(int i=2;i<=300;i+=3) cout<<ans[i]<<" "; cout<<endl;*/
    int T=read();
    while(T--){
        int n=read();
        solve(n);
    }
    return 0;
}
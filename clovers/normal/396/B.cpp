/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
ll mul(ll a,ll b,ll mod){
	return (a*b-(ll)((long double)a/mod*b)*mod+mod)%mod;
}
ll qpow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b&1) ret=mul(ret,a,mod);
        a=mul(a,a,mod); 
        b>>=1;
    }
    return ret;
}
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
typedef pair<int,int> pii;
#define ull unsigned long long
int Rand(){return rand()&32767;}
ll ran(ll l,ll r){
    ull ret=((ull)Rand()<<15)+Rand();
    return ret%(r-l+1)+l;
}
pii operator + (pii A,pii B){
    int g=__gcd(A.second,B.second);
    pii ret=mk(B.second/g*A.first+A.second/g*B.first,A.second/g*B.second);
    g=__gcd(ret.first,ret.second);
    ret.first/=g; ret.second/=g;
    return ret;
}
pii operator - (pii A,pii B){
    int g=__gcd(A.second,B.second);
    pii ret=mk(B.second/g*A.first-A.second/g*B.first,A.second/g*B.second);
    g=__gcd(ret.first,ret.second);
    ret.first/=g; ret.second/=g;
    return ret;
}
bool MR(ll n){
    if(n<3) return n==2;
    ll a=n-1,b=0;
    while(a%2==0) a/=2,b++;
    for(int i=1,j;i<=8;i++){
        ll x=ran(1,n-2),v=qpow(x,a,n);
        if(v==1||v==n-1) continue;
        for(j=0;j<b;j++){
            v=mul(v,v,n);
            if(v==n-1) break;
        }
        if(j>=b) return 0;
    }
    return 1;
}

signed main()
{
    int T=read();
    while(T--){
        int n=read();
        int L,R;
        for(int i=n;i>=1;i--) if(MR(i)){L=i; break;}
        for(int i=n+1;i<=2e9;i++) if(MR(i)){R=i; break;}
        pii A=mk(1,2),B=mk(1,L),C=mk(n-L+1,L*R);
        int g=__gcd(C.first,C.second); C.first/=g; C.second/=g;
        A=A-B; A=A+C;
        printf("%lld/%lld\n",A.first,A.second);
    }
    return 0;
}
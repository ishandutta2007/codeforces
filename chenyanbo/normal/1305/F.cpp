#pragma GCC optimize("Ofast")
#pragma GCC target("avx") 
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3f
#define y0 _lxybz_
#define y1 _ljmnzyzhhhoscartxdy_
typedef long double ld;
typedef long long ll;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize
#define lo(x) ((x)&(-(x)))
#define trav(a, x) for (auto &a : x)
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
const ld Pi = 4*atan((ld)1);
template<class T> void chmin(T &a,const T&b) { a = min(a, b); }
template<class T> void chmax(T &a,const T&b) { a = max(a, b); }
namespace IO{
template<class T> inline void read(T&ret)
{
	ret=0; int f=1; char c=getchar();
	while(c<48||c>57){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	ret*=f;
}
template<class T> inline void prin(const T&ret)
{
	if(!ret){putchar(48);return;} static T o; o=ret;
	if(o<0){putchar('-');o=-o;}
	static int op[25],tt; tt=0;
	while(o){
		op[++tt]=o%10;
		o/=10;
	}
	for(int i=tt;i;--i)putchar(op[i]+48);
}
template<class T> inline void pri_(const T&ret)
{
	prin(ret);putchar(' ');
}
template<class T> inline void priE(const T&ret)
{
	prin(ret);putchar('\n');
}
}
using namespace IO;
 
#define N 9000060
#define LL long long
ll ss,m,Ans,v[N],tt,c[N],a[200500];
int n;
unordered_map<LL,int>Vi;
LL mul(LL a,LL b,LL p){//LL
    a%=p;
    LL res=0;
    while(b){
        if(b&1)res=(res+a)%p;
        b>>=1;
        a=(a<<1)%p;
    }
    return res;
}
LL qpow(LL a,LL b,LL p){//
    a%=p;b%=p;
    LL ans=1;
    while(b){
        if(b&1){
            ans=mul(ans,a,p);
        }
        b>>=1;
        a=mul(a,a,p);
    }
    return ans;
}
LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}
bool Miller_Rabin(LL n){
    if(n==2)return true;
    if(n<2||!(n&1))return false;
    int cishu=20,ji=0;
    LL m=n-1;
    while(!(m&1)){
        ji++;
        m>>=1;
    }
    srand(100);
    while(cishu--){
        LL a=rand()%(n-1)+1;
        LL x=qpow(a,m,n),tmp=0;
        for(int i=0;i<ji;i++){
            tmp=mul(x,x,n);
            if(tmp==1&&x!=1&&x!=n-1)return false;
            x=tmp;
        }
        if(tmp!=1)return false;
    }
    return true;
}
LL Pollard_Rho(LL n,int c){
    LL i=1,k=2,x,y;
    x=rand()%(n-1)+1;y=x;
    while(1){
        i++;
        x=(mul(x,x,n)+c)%n;
        if(y==x)return n;
        LL d=gcd((y-x+n)%n,n);
        if(d!=1&&d!=n)return d;     
        if(i==k){
            y=x;
            k<<=1;
        }
    }
}
void find(LL n){
    if(n==1)return;
    if(Miller_Rabin(n)){
        v[++tt]=n;
        return;
    }
    LL p=n;
    while(p>=n)p=Pollard_Rho(p,rand()%(n-1)+1);
    find(p);
    find(n/p);
}
 
inline void _Sol_()
{
	read(n);F(i,1,n)read(a[i]);
	F(i,1,n)if(a[i]&1)++Ans;
	random_shuffle(a+1,a+n+1);
	F(i,1,min(n,500)){
		find(a[i]);if(a[i]>1)find(a[i]-1);find(a[i]+1);
	}
	F(i,1,tt){
		if(!Vi[v[i]])c[++m]=v[i],Vi[v[i]]=1;
	}
	srand(20001111);
	random_shuffle(c+1,c+m+1);
	random_shuffle(a+1,a+n+1);
//	sort(c+1,c+m+1);
//	sort(a+1,a+n+1);
	F(i,1,m){
		ss=0;
		F(j,1,n){
			if(a[j]<c[i])ss+=c[i]-a[j];
			else ss+=min(a[j]%c[i],(-a[j]%c[i])+c[i]);
			if(ss>=Ans)break;
		}
		chmin(Ans,ss);
	}
	priE(Ans);
}
 
int main()
{	
	int T=1; //read(T);
	while(T--)_Sol_();
}
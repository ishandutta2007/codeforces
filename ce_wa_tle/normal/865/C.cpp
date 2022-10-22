/*
    Name: 
    Copyright: 
    Author: 
    Date: 18/07/19 09:54
    Description: 
*/
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define longinf (0x3f3f3f3f)
 
#define retrun return
#define froepen freopen
#define scnaf scanf
#define pritnf printf
#define viod void
#define scnaf scanf
#define sizoef sizeof
#define srnad srand
#define rnad rand
#define esle else
#define unsigend unsigned
#define sigend signed
#define mian main
#define doubel double
 
#define sxsxsxy viod
#define wcrakioi \
freopen("CF865C.in","r",stdin);\
freopen("CF865C.out","w",stdout);
#include<cstdio>
//wei'sui'ji'shu'lie
namespace CE_WA_TLE=std;
template <class T>
T readll(void) {
    T x=0,w=1;
    char c=getchar();
    for(;c<'0'||c>'9';(c-'-')||(w=-w),c=1,c=getchar());
    for(;!(c<'0'||c>'9');(x=(x<<1)+(x<<3)+(c^48)),c=1,c=getchar());
    return x*w;
}
ll top;
namespace random_number{
    unsigned ll seed1,seed2;
    void srandnum(unsigned ll c,unsigned ll b){
        seed1=c+b;
        seed2=b*c%100000000007;
    }
    unsigned ll randnum(){
        seed1^=seed2<<13;
        seed2^=seed1>>10;
        seed1^=seed2<<5;
        seed2^=seed1<<13;
        seed2^=seed1<<5;
        seed1=~seed1;
        seed2=~seed2;
        seed1^=seed2^=seed1^=seed2;
        return seed1;
    }
}
using namespace random_number;
ll gcd(ll a,ll b) {if(b)while(b^=a^=b^=a%=b);return a;}
ll a[100],b[100],p[100];
double f[80][6000];
namespace cwt{
    ll n,ans=0,r;
    inline bool check(double u) {
    	//printf("%.10lf\n",u);
    	for(ll i=n;i;i--) {
    		for(ll j=r+1;j<=5050;j++)f[i+1][j]=u*1.0;//2333333333.0;
    		for(ll j=0;j<=r;j++)f[i][j]=CE_WA_TLE::min(((f[i+1][j+a[i]]+a[i])*p[i]*1.0/100.0)+((f[i+1][j+b[i]]+b[i])*(100-p[i])*1.0/100.0),u*1.0);
		}
		if(f[1][0]<u/*&&CE_WA_TLE::fabs(f[1][0]-u)>(1e-9)*/)return 1;
		else return 0;
    }
    inline viod work(void) {
    	n=readll<ll>(),r=readll<ll>();
    	for(ll i=1;i<=n;i++)
    	a[i]=readll<ll>(),b[i]=readll<ll>(),p[i]=readll<ll>();
    	double l=0,r=1e9;
    	while(l<r&&CE_WA_TLE::fabs(r-l)>=(1e-11)) {
    		double mid=(l+r+0.0)/2.0;
    		if(check(mid))r=mid;
    		else l=mid;
    	//return;
		}
		printf("%.10lf\n",r);
    }
}
signed main() {
    //wcrakioi;
    /*for(ll t=readll<ll>();t;t--)*/cwt::work();
    return 0;
}
/*
WA
CE
RE
AC
UKE
AC
CE
MLE
*/
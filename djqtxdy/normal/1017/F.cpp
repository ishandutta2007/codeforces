#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
namespace Mymath{
	LL qp(LL x,LL p,LL mod){
		LL ans=1;
		while (p){
			if (p&1) ans=ans*x%mod;
			x=x*x%mod;
			p>>=1;
		}
		return ans;
	}
	LL inv(LL x,LL mod){
		return qp(x,mod-2,mod);
	}
	LL C(LL N,LL K,LL fact[],LL mod){
		return fact[N]*inv(fact[K],mod)%mod*inv(fact[N-K],mod)%mod;
	}
	template <typename Tp> Tp gcd(Tp A,Tp B){
		if (B==0) return A;
		return gcd(B,A%B);
	}
	template <typename Tp> Tp lcm(Tp A,Tp B){
		return A*B/gcd(A,B);
	}
};
namespace fwt{
	using namespace Mymath;
	void FWT(int a[],int n,LL mod)
	{
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
	                //xor:a[i+j]=x+y,a[i+j+d]=x-y;
	                //and:a[i+j]=x+y;
	                //or:a[i+j+d]=x+y;
	            }
	}

	void UFWT(int a[],int n,LL mod)
	{
		LL rev=inv(2,mod);
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
	                //xor:a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
	                //and:a[i+j]=x-y;
	                //or:a[i+j+d]=y-x;
	            }
	}
	void solve(int a[],int b[],int n,LL mod)
	{
	    FWT(a,n,mod);
	    FWT(b,n,mod);
	    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;
	    UFWT(a,n,mod);
	}
};
//%6==1 %6==5
const int Maxn=1e8+5;
const int Maxm=3e8+5;
bitset<Maxn> isp;
void _init(){
	for (int i=0;i<Maxn;i++) isp[i]=true;
	//6(i/2)+1 , 6(i/2)+5
	isp[0]=false;
	for (int i=3;i<Maxm;i+=2){
		if (i%6!=1  && i%6!=5) continue;
		int id=i/6;
		id=id*2;
		if (i%6==5) id++;
		if (isp[id] && i*i<Maxm){
			for (int j=i+i;j<Maxm;j+=i){
				if (j%6==1 || j%6==5){
					int ij=j/6*2;
					if (j%6==5) ij++;
					isp[ij]=false;
				}
			}
		}
	}
} 
inline bool check(int x){
	if (x==2|| x==3) return true;
	if (x%6!=1 && x%6!=5) return false;
	int ix=x/6*2+(x%6==5);
	return isp[ix];
}
LL n;
LL A,B,C,D;
const LL mod=4294967296LL;
LL F(LL X){
	return (A*X%mod*X%mod*X+B*X%mod*X+C*X+D) %mod;
}
int main(){
	_init();
	cin>>n>>A>>B>>C>>D;
	if (n==1){
		printf("0\n");
		return 0;
	}
	LL ans=0;
	if (1){
		LL j=2;
		LL f=F(2);
		while (j<=n){
			ans+=(n/j)*f;
			ans%=mod;
			j=j*2;
		}
	}
	for (LL i=3;i<=n;i+=2){
		if (check(i)){
			LL j=i;
			LL f=F(i);
			while (j<=n){
				ans+=(n/j)*f;
				ans%=mod;
				j=j*i;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
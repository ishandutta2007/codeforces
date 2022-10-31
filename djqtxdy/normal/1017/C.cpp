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
const int Maxn=100005;
int a[Maxn];
int main(){
	int n;
	cin>>n;
	int x=sqrt(n);
	if (x*x==n){
		for (int i=1;i<=x;i++){
			for (int j=(i-1)*x+1;j<=(i)*x;j++){
				a[j]=(i-1)*x+(x-(j-(i-1)*x)+1);
			}
		}
		for (int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return 0;
	}
	int y=n-x*x;
	if (y<=x){
		int beg=1;
		for (int i=1;i<=x;i++){
			int len;
			if (i>=x-y+1) len=x+1;
			else len=x;
			for (int j=beg;j<=beg+len-1;j++){
				a[j]=beg+len-(j-beg)-1;
			}
			beg=beg+len;
		}
		for (int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return 0;
	}
	else{
		int beg=1;
		y-=x;
		for (int i=1;i<=x+1;i++){
			int len;
			if (i>=x-y+2) len=x+1;
			else len=x;
			for (int j=beg;j<=beg+len-1;j++){
				a[j]=beg+len-(j-beg)-1;
			}
			beg=beg+len;
		}
		for (int i=1;i<=n;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return 0;
	}
}
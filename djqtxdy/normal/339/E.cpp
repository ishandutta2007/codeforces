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
const int Maxn=1005;
int a[Maxn],n;
int b[Maxn];
int c[Maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	vector<int> pos;
	for (int i=2;i<=n-1;i++){
		if (a[i]-a[i-1]!=a[i+1]-a[i]){
			pos.pb(i);
			pos.pb(i-1);//pos.pb(i+1);
		}
		if (abs(a[i]-a[i-1])!=1) pos.pb(i);
	}
	bool flag=true;
	pos.pb(1);pos.pb(n);
	
	for (int i=1;i<=n;i++){
		if (a[i]!=i) flag=false;
	}
	if (flag){
		printf("0\n");
		return 0;
	}
	sort(pos.begin(),pos.end());
	pos.resize(unique(pos.begin(),pos.end())-pos.begin());
	for (int L1=0;L1<pos.size();L1++){
		for (int R1=L1+1;R1<pos.size();R1++){
			int l1=pos[L1],r1=pos[R1];
			for (int j=1;j<=n;j++) b[j]=a[j];
			for (int j=l1;j<=r1;j++){
				if (j<r1+l1-j){
					swap(b[j],b[r1+l1-j]);
				}
			}
			bool flag=true;
			for (int j=1;j<=n;j++){
				if (b[j]!=j) flag=false;
			}
			if (flag){
				printf("1\n%d %d\n",l1,r1);
				return 0;
			}
			vector<int>pos2;
			for (int j=2;j<=n-1;j++){
				if (b[j]-b[j-1]!=b[j+1]-b[j]){
					pos2.pb(j);pos2.pb(j-1);
					//pos2.pb(j+1);
				}
				if (abs(b[j]-b[j-1])!=1) pos2.pb(j);
			}
			pos2.pb(1);
			pos2.pb(n);
			sort(pos2.begin(),pos2.end());
			pos2.resize(unique(pos2.begin(),pos2.end())-pos2.begin());
			if (pos2.size()>16){
				continue;
			}
			for (int L2=0;L2<pos2.size();L2++){
				int l2=pos2[L2];
				for (int R2=L2+1;R2<pos2.size();R2++){
					int r2=pos2[R2];
					for (int i=1;i<=n;i++){
						c[i]=b[i];
					}
					for (int j=l2;j<=r2;j++){
						if (j<r2+l2-j){
							swap(c[j],c[r2+l2-j]);
						}
					}
					bool flag=true;
					int st=-1;
					for (int j=1;j<=n;j++){
						if (c[j]!=j){
							flag=false;
							st=j;
							break;
						}
					}
					if (flag){
						printf("2\n%d %d\n%d %d\n",l2,r2,l1,r1);
						return 0;
					}
					int ed=-1;
					for (int j=n;j>=1;j--){
						if (c[j]!=j){
							ed=j;
							break;
						}
					}flag=true;
					for (int j=st;j<=ed;j++){
						if (c[j]!=ed+st-j){
							flag=false;
							break;
						}
					}
					if (flag){
						printf("3\n%d %d\n%d %d\n%d %d\n",st,ed,l2,r2,l1,r1);
						return 0;
					}
				}
			}
		}
	}
}
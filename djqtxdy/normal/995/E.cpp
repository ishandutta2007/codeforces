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
#include<unordered_map>
unordered_map<LL,LL> x,y;
LL u,v,p;
using namespace Mymath;
void Add(LL X,LL prv,vector<pair<LL,LL> > &tmp){
	X=(X+p)%p;
	tmp.pb(mp(X,prv));
}
int main(){
	cin>>u>>v>>p;
	vector<int> ans;
	if (u==v){
		cout<<2<<endl<<1<<' '<<2<<endl;
		return 0;
	}
	if ((v-u+p)%p<=200){
		while (1){
			u++;
			ans.pb(1);
			u%=p;
			if (u==v) break;
		}
		printf("%d\n",ans.size());
		for (int i=0;i<ans.size();i++){
			printf("%d ",ans[i]);
		}
		return 0;
	}
	if ((u-v+p)%p<=200){
		while (1){
			u--;
			u+=p;
			ans.pb(2);
			u%=p;
			if (u==v) break;
		}
		printf("%d\n",ans.size());
		for (int i=0;i<ans.size();i++){
			printf("%d ",ans[i]);
		}
		return 0;
	}
	int cur=u;
	x[u]=-1;
	for (int i=0;i<=30;i++){
		vector<pair<LL,LL> > XX;
		for (auto X:x){
			int Y=X.first;
			if (rand()%3<2)Add(Y+1,Y,XX);
			if (rand()%3<2)Add(Y-1,Y,XX);
			Add(inv(Y,p),Y,XX);
		}
		for (auto X:XX){
			LL fi=X.first,se=X.second;
			if (!x.count(fi)) x[fi]=se;
		}
		if (x.size()>=300000) break;
	}
	y[v]=-1;
	for (int t=0;t<=30;t++){
	//	cout<<t<<endl;
		vector<pair<LL,LL> > XX;
		for (auto X:y){
			int Y=X.first;
			if (x.count(Y)){
				vector<LL> ans;
				LL Z=Y;
				while (Z!=-1){
					ans.pb(Z);
					Z=x[Z];
				}
				reverse(ans.begin(),ans.end());
				Z=Y;
				while (Z!=v){
					Z=y[Z];
					ans.pb(Z); 
				}
				vector<int> res;
				for (int i=1;i<ans.size();i++){
					LL now=ans[i],prv=ans[i-1];
					if ((now-prv+p)%p==1){
						res.pb(1);
					}
					else if ((prv-now+p)%p==1){
						res.pb(2);
					}
					else{
						res.pb(3);
					}
				}
				printf("%d\n",res.size());
				for (int i=0;i<res.size();i++){
					printf("%d ",res[i]);
				}
				return 0;
			}
			if (rand()%3<2)Add(Y+1,Y,XX);
			if (rand()%3<2)Add(Y-1,Y,XX);
			Add(inv(Y,p),Y,XX);
		}
		for (auto X:XX){
			LL fi=X.first,se=X.second;
			if (!y.count(fi)) y[fi]=se;
		}
	}
} 
/*
1 1000000000 1000000007
*/
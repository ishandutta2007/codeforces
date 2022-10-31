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
const int Maxn=1e5+5;
LL x[Maxn],v[Maxn];
LL w;
pair<LL,LL> st[Maxn],ed[Maxn];
pair<LL,LL> dd[Maxn];
int ord[Maxn];
int id[Maxn];
bool cmp(int x,int y){
	if (st[x].first*st[y].second!=st[x].second*st[y].first){
		return st[x].first*st[y].second<st[x].second*st[y].first;
	}
	return ed[x].first*ed[y].second>ed[x].second*ed[y].first;
}
bool cmp2(pair<LL,LL> x,pair<LL,LL> y){
	return x.first*y.second<x.second*y.first;
}
int bit[Maxn];
void add(int pos){
	while (pos<Maxn){
		bit[pos]++;
		pos+=pos&-pos;
	}
}
int query(int pos){
	int ret=0;
	while (pos){
		ret+=bit[pos];
		pos-=pos&-pos;
	}
	return ret;
}
int main(){
	int n=read();
	w=read();
	for (int i=1;i<=n;i++){
		x[i]=read();v[i]=read();
		x[i]=-x[i];
		st[i]=mp(x[i],v[i]+w);
		ed[i]=mp(x[i],v[i]-w);
		/*
		if ((double)st[i].first/st[i].second>(double)ed[i].first/ed[i].second){
			swap(st[i],ed[i]);
		}*/
		if (st[i].first<0) st[i].first=-st[i].first,st[i].second=-st[i].second;
		if (ed[i].first<0) ed[i].first=-ed[i].first,ed[i].second=-ed[i].second;
		//cout<<"st"<<' '<<(double)st[i].first/st[i].second<<endl;
		//cout<<"ed"<<' '<<(double)ed[i].first/ed[i].second<<endl;
		ord[i]=i;
		dd[i]=ed[i];
	}
	sort(ord+1,ord+1+n,cmp);
	sort(dd+1,dd+1+n,cmp2);
	for (int i=1;i<=n;i++){
		int lo=1,hi=n+1;
		while (hi-lo>1){
			int mid=lo+hi>>1;
			if (ed[i].first*dd[mid].second>=ed[i].second*dd[mid].first){
				lo=mid;
			}
			else{
				hi=mid;
			}
		}
		id[i]=lo;
	}
	LL ans=0; 
	for (int i=1;i<=n;i++){
		int ii=ord[i];
		ans+=query(n)-query(id[ii]-1);
		add(id[ii]);
	}
	printf("%I64d\n",ans);
	return 0;
}
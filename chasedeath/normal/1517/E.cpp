#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,P=998244353;

int n,a[N];
ll s[N],t[N];

int Calc(int i,ll d){
	int ans=0;
	int res=-1;
	//cout<<d<<endl;
	for(int l=0,r=(i-1)/2,mid;l<=r;) 
		if(mid=(l+r)>>1,d-t[i]+t[i-mid*2]-s[i-mid*2]>0) r=mid-1,res=mid;
		else l=mid+1;
	//cout<<res<<endl;
	if(~res) ans+=(i-1)/2-res+1;
	if(i==1) return ans;
	res=-1;
	for(int l=0,r=(i-2)/2,mid;l<=r;) 
		if(mid=(l+r)>>1,d-t[i]+t[i-mid*2]-s[i-mid*2]+2*a[1]>0) r=mid-1,res=mid;
		else l=mid+1;
	//cout<<res<<endl;
	if(~res) ans+=(i-2)/2-res+1;
	return ans;
}

int main(){
	rep(_,1,rd()) {
		n=rd();
		rep(i,1,n) a[i]=rd();
		rep(i,1,n) s[i]=s[i-1]+a[i];
		rep(i,1,n) t[i]=a[i]-t[i-1];
		ll ans=0;
		//cout<<Calc(2,s[n-1]-s[2]-a[n])<<endl;
		//return 0;
		rep(i,1,n-1) {
			//cout<<"$"<<i<<' '<<Calc(i,s[n]-s[i])<<endl;
			//cout<<"$"<<i<<' '<<Calc(i,s[n-1]-s[i]-a[n])<<endl;
			ans+=Calc(i,s[n]-s[i]);
			if(i<n-1) ans+=Calc(i,s[n-1]-s[i]-a[n]);
		}
		rep(i,1,n) if(s[i]-(s[n]-s[i])>0) ans++;
		printf("%lld\n",ans%P);
	}
}
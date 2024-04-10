#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e6;
struct F{ 
	ll a,b; 
	__int128 query(ll x){
		return (__int128)a*x+b;
	}
}f[N],q[N];
ll a[N];
template<class T> void pi(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) pi(x/10);
	putchar(x%10+'0');
}
ll getIP(F x,F y){
	return (x.b-y.b)/(y.a-x.a);
}
bool cmp(F x,F y,F z){
	if((z.a-x.a>0)^(z.a-y.a>0)) return (__int128)(x.b-z.b)*(z.a-y.a)>(__int128)(y.b-z.b)*(z.a-x.a);
	else return (__int128)(x.b-z.b)*(z.a-y.a)<(__int128)(y.b-z.b)*(z.a-x.a);
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+n+1);
		f[1]=(F){0,0};
		for(int i=2;i<=n;++i){
			f[1].a+=(a[1]+a[i]),f[1].b+=1ll*a[1]*a[i]; 
		}
		for(int i=2;i<n;++i){
			f[i].a=f[i-1].a+a[n]-a[1];
			f[i].b=f[i-1].b+1ll*a[n]*a[i]-1ll*a[1]*a[i];
		}
//		for(int i=1;i<=n;++i) printf("<%lld %lld>",f[i].a,f[i].b);
//		puts("");
		int top=0;
		for(int i=n-1;i>=1;--i){
			while(top>0&&q[top].a==f[i].a&&q[top].b>=f[i].b) --top;
			while(top>1&&cmp(f[i],q[top],q[top-1])) --top;
			q[++top]=f[i];
		}
/*		for(int i=1;i<=top;++i)
			printf("(%lld %lld)",q[i].a,q[i].b);
		puts("");
*/		if(q[1].a<0||q[top].a>0) puts("INF");
		else{
			__int128 ans=-(__int128)1e36;
			for(int i=1;i<=top;++i)
				if(q[i].a==0) ans=max(ans,(__int128)q[i].b);
			for(int i=1;i<top;++i){
				__int128 x=(__int128)q[i].a*(q[i].b-q[i+1].b),y=(q[i+1].a-q[i].a);
				if(x%y==0) 
					ans=max(ans,x/y+q[i].b);
			}
			pi(ans); puts("");	
		}
	}
}
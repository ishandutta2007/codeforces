#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline long long Max(long long a,long long b){return a>b?a:b;}
inline long long Min(long long a,long long b){return a<b?a:b;}
const int o=2e5+10;
int n,q;long long a[o],x,y,s,ans;
int main(){
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),s+=a[i];
	sort(a+1,a+1+n);
	read(q);
	for(int l,r,md;q--;){
		read(x);read(y);
		for(l=1,r=n+1;l<r;)
			if(x<=a[md=l+r>>1]) r=md;
			else l=md+1;
		if(l==n+1){printf("%lld\n",x-a[n]+Max(0,y-(s-a[n])));continue;}
		ans=Max(0,y-(s-a[l]));
		if(--l) ans=Min(ans,x-a[l]+Max(0,y-(s-a[l])));
		for(l=0,r=n;l<r;)
			if(y<=s-a[md=(l+r>>1)+1]) l=md;
			else r=md-1;
		if(l) ans=Min(ans,Max(0,x-a[l]));
		printf("%lld\n",ans);
	}
	return 0;
}
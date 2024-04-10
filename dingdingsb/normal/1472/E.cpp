#include<bits/stdc++.h>
namespace in{
	#ifdef slow
	inline int getc(){return getchar();}
	#else
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#endif
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
int t,n;const int N=2e5+100;
pair<pair<int,int>,int>p[N];
#define w first.first
#define h first.second
#define id second
#define mp make_pair
int ans[N];
pair<int,int>f[N];
signed main(){
	in::read(t);
	while(t--){
		in::read(n);
		for(int i=1;i<=n;i++)
			in::read(p[i].w,p[i].h),p[i].id=i;
		sort(p+1,p+1+n);
		for(int i=1;i<=n;i++)ans[i]=-1;
		f[0]={0x3f3f3f3f,-1};
		for(int i=1;i<=n;i++)
			f[i]=min(f[i-1],{p[i].h,p[i].id});
		for(int i=1;i<=n;i++){
			int p1=lower_bound(p+1,p+1+n,mp(mp(p[i].w,0),0))-p-1;
			if(p[i].h>f[p1].first)ans[p[i].id]=f[p1].second;
			int p2=lower_bound(p+1,p+1+n,mp(mp(p[i].h,0),0))-p-1;
			if(p[i].w>f[p2].first)ans[p[i].id]=f[p2].second;
		}
		for(int i=1;i<=n;i++)out::write(ans[i]),out::putc(' ');out::putc('\n'); 
	}
	out::flush();
	return 0;
}
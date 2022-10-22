#include<bits/stdc++.h>
//#define faster
namespace in{
	#ifdef faster
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	#else
	inline int getc(){return getchar();}
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
int t,n;vector<int>a,f,g;
#define chkmn(a,b) (a)=min((a),(b))
signed main(){
	in::read(t);
	while(t--){
		in::read(n);
		a=vector<int>(n+10,0);
		f=vector<int>(n+10,0);
		g=vector<int>(n+10,0);
		for(int i=1;i<=n;i++)in::read(a[i]);
		for(int i=3;i<=n;i++){
			f[i]=f[i-1];
			if(a[i]<a[i-1]&&a[i-1]>a[i-2])f[i]++;
			if(a[i]>a[i-1]&&a[i-1]<a[i-2])f[i]++;
		}
		for(int i=n-2;i>=1;i--){
			g[i]=g[i+1];
			if(a[i]<a[i+1]&&a[i+1]>a[i+2])g[i]++;
			if(a[i]>a[i+1]&&a[i+1]<a[i+2])g[i]++;
		}
		int ans=f[n];
		for(int i=1;i<=n;i++){
			if(i==1||i==2){
				chkmn(ans,g[i+1]);
			}
			else if(i==n||i==n-1){
				chkmn(ans,f[i-1]);
			}
			else{
				//a[i-2] a[i-1] X a[i+1] a[i+2]
				if(a[i-2]>a[i-1]&&a[i-1]<a[i+1]&&a[i+1]>a[i+2])
					chkmn(ans,f[i-1]+g[i+1]+1);
				else if(a[i-2]<a[i-1]&a[i-1]>a[i+1]&&a[i+1]<a[i+2])
					chkmn(ans,f[i-1]+g[i+1]+1);
				else chkmn(ans,f[i-1]+g[i+1]);
			}
		}out::write(ans);out::putc('\n');
	}
	out::flush();
	return 0;
}
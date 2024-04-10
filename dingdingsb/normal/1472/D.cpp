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
const int N=2e5+10;
int t,n,x,a[N],la,b[N],lb;
signed main(){
	in::read(t);
	while(t--){
		in::read(n);la=lb=0;
		for(int i=1;i<=n;i++)
			in::read(a[i]);
		//a b
		sort(a+1,a+n+1);reverse(a+1,a+1+n);
		long long ans[2]={0,0};
		for(int i=1;i<=n;i++)
			if(a[i]%2==0&&i%2==1)ans[0]+=a[i];
			else if(a[i]%2==1&&i%2==0)ans[1]+=a[i];
		if(ans[0]>ans[1])puts("Alice");
		else if(ans[0]==ans[1])puts("Tie");
		else puts("Bob");
	}
	out::flush();
	return 0;
}
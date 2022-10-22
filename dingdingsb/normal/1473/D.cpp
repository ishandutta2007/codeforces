#include<bits/stdc++.h>
//#define faster
namespace In{
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
const int N=2e5+100;
int t,n,m;char str[N];
int mx[N],mn[N],lst[N];
int in[N],de[N],ll[N];
signed main(){
	In::read(t);
	while(t--){
		In::read(n,m);
		scanf("%s",str+1);
		lst[0]=0;
		#define chkmx(a,b) (a)=max((a),(b))
		#define chkmn(a,b) (a)=min((a),(b))
		for(int i=1;i<=n;i++){
			if(str[i]=='+')
				lst[i]=lst[i-1]+1;
			else lst[i]=lst[i-1]-1;
			mx[i]=mx[i-1];chkmx(mx[i],lst[i]);
			mn[i]=mn[i-1];chkmn(mn[i],lst[i]);
		}
		in[n+1]=de[n+1]=ll[n+1]=0;
		for(int i=n;i>=1;i--){
			if(str[i]=='+')
				ll[i]=ll[i+1]-1;
			else ll[i]=ll[i+1]+1;
			in[i]=in[i+1];chkmx(in[i],ll[i]);
			de[i]=de[i+1];chkmn(de[i],ll[i]);
		}
		while(m--){
			int l,r;In::read(l,r);
			int mmx=max(mx[l-1],lst[l-1]+(in[r+1]-ll[r+1]));
			int mmn=min(mn[l-1],lst[l-1]-(ll[r+1]-de[r+1]));
			out::write(mmx-mmn+1);out::putc('\n');
		}
	}
	out::flush();
	return 0;
}
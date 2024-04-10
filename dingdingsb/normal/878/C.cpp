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
int n,k;
struct node{
	int sz,mn[15],mx[15];
	bool operator<(const node b)const{
		for(int i=1;i<=k;i++)
			if(mx[i]>b.mn[i])
				return false;
		return true;
	}
};
node t;set<node>s;
#define chkmn(a,b) (a)=min((a),(b))
#define chkmx(a,b) (a)=max((a),(b))
signed main(){
	in::read(n,k);
	for(int i=1;i<=n;i++){
		t.sz=1;for(int j=1;j<=k;j++)in::read(t.mn[j]),t.mx[j]=t.mn[j];
		for(auto it=s.find(t);it!=s.end();it=s.find(t)){
			for(int j=1;j<=k;j++)chkmn(t.mn[j],it->mn[j]);
			for(int j=1;j<=k;j++)chkmx(t.mx[j],it->mx[j]);
			t.sz+=it->sz;s.erase(it);
		}
		s.insert(t);out::write((--s.end())->sz);out::putc('\n');
	}
	out::flush();
	return 0;
}
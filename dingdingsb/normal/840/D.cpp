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
const int N=3e5+100,sz=550;
int n,a[N],m,ans[N];
struct Qry{
	int l,r,k,id;
	bool operator<(const Qry&b)const{
		return l/sz==b.l/sz?r<b.r:l<b.l;
	}
}Q[N];
int sum[N];
void add(int x){sum[a[x]]++;}
void del(int x){sum[a[x]]--;}
typedef std::mt19937  Random_mt19937;
Random_mt19937  rnd(time(0));
signed main(){
	in::read(n,m);
	for(int i=1;i<=n;i++)in::read(a[i]);
	for(int i=1;i<=m;i++)
		in::read(Q[i].l,Q[i].r,Q[i].k),Q[i].id=i,ans[i]=0x3f3f3f3f;
	sort(Q+1,Q+1+m);
	for(int i=1,l=Q[1].l,r=l-1;i<=m;i++){
		while(l>Q[i].l)add(--l);
		while(r<Q[i].r)add(++r);
		while(l<Q[i].l)del(l++);
		while(r>Q[i].r)del(r--);
		int ci=200;
		while(ci--){
			int now=rnd()%(Q[i].r-Q[i].l+1)+Q[i].l;
			if(sum[a[now]]>(Q[i].r-Q[i].l+1)/Q[i].k)
				ans[Q[i].id]=min(ans[Q[i].id],a[now]);
		}
	}
	for(int i=1;i<=m;i++)
		out::write(ans[i]==0x3f3f3f3f?-1:ans[i]),out::putc('\n');
	out::flush();
	return 0;
}
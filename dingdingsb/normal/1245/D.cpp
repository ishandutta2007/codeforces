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
const int N=2001;
struct node{
	int u,v;long long w;
	bool operator<(const node &b)const{
		return w<b.w;
	}
}e[N*N/2+10];
int n,cnt,x[N],y[N],c[N],k[N];
struct DSU{
	int fa[N];
	DSU(){for(int i=0;i<N;i++)fa[i]=i;}
	int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
	void merge(int x,int y){fa[getfa(y)]=getfa(x);}
}D;
void add(int u,int v,long long w){cnt++,e[cnt]={u,v,w};}
vector<int>A;vector<pair<int,int> >B;
signed main(){
	in::read(n);
	for(int i=1;i<=n;i++)in::read(x[i],y[i]);
	for(int i=1;i<=n;i++)in::read(c[i]),add(0,i,c[i]);
	for(int i=1;i<=n;i++)in::read(k[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			add(i,j,1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])));
	sort(e+1,e+cnt+1);long long ans=0;
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v;
		if(D.getfa(u)!=D.getfa(v)){
			D.merge(u,v);
			ans+=e[i].w;
			if(u==0)A.push_back(v);
			else B.push_back({u,v});
		}
	}
	out::write(ans);out::putc('\n');
	out::write(A.size());out::putc('\n');
	for(auto x:A)out::write(x),out::putc(' ');out::putc('\n');
	out::write(B.size());out::putc('\n');
	for(auto x:B)out::write(x.first),out::putc(' '),out::write(x.second),out::putc('\n');
	out::flush();
	//cout<<"lalala";
	return 0;
}
#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
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
	inline void puts(char*s){int l=0;while(s[l])putc(s[l++]);putc('\n');}
}
using namespace std;
const int N=3e5+10;
int T,n,m;vector<int>e[N]; 
bool vis[N],flag[N];
void dfs(int u){
	vis[u]=true;
	bool use=true;
	for(auto v:e[u])
		if(flag[v])use=false;
	flag[u]=use;
	//printf("%d %d\n",u,use);
	for(auto v:e[u])
		if(!vis[v])dfs(v);
}
signed main(){
	in::read(T);
	while(T--){
		in::read(n,m);
		for(int i=1;i<=n;i++)
			vis[i]=false,flag[i]=false,e[i].clear();
		for(int i=1;i<=m;i++){
			int u,v;in::read(u,v);
			e[u].push_back(v);e[v].push_back(u);
		}
		dfs(1);
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				out::puts("NO");
				goto loop;
			}
		out::puts("YES");
		for(int i=1;i<=n;i++)
			if(flag[i])
				cnt++;
		out::write(cnt);out::putc('\n');
		for(int i=1;i<=n;i++)
			if(flag[i])out::write(i),out::putc(' ');
		out::putc('\n');
		loop:;
	}
	out::flush();
	return 0;
}
#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){
	    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
	}
	template <typename T>inline void read(T& t){
	    t=0;int f=0;char ch=getc();
	    while (!isdigit(ch)){
	        if(ch=='-')f = 1;
	        ch=getc();
	    }
	    while(isdigit(ch)){
   	    	t=t*10+ch-48;
   	    	ch = getc();
   		}
		if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){
	    read(t);read(args...);
	}
}
namespace out{
	char buffer[1<<21];
	int p1=-1;
	const int p2 = (1<<21)-1;
	inline void flush() {
		fwrite(buffer,1,p1+1,stdout),
		p1=-1;
	}
	inline void putc(const char &x) {
		if(p1==p2)flush();
		buffer[++p1]=x;
	}
	template <typename T>void write(T x) {
		static char buf[15];
		static int len=-1;
		if(x>=0){
			do{
    			buf[++len]=x%10+48,x/=10;
    		}while (x);
		}else{
    		putc('-');
			do {
    			buf[++len]=-(x%10)+48,x/=10;
			}while(x);
		}
		while (len>=0)
			putc(buf[len]),--len;
	}
}
using namespace std;
int t,n,du[100000+100]; 
vector<int>e[100000+100];
int size[100000+100];
int ans,val;
int tmp[100000+100];
void dfs(int u,int fa){
	size[u]=1;tmp[u]=-1;
	for(auto v:e[u])
		if(v!=fa)
			dfs(v,u),size[u]+=size[v],tmp[u]=max(tmp[u],size[v]);
	tmp[u]=max(tmp[u],n-size[u]);
	if(tmp[u]<val)val=tmp[u],ans=u;
}
signed main(){
	in::read(t);
	while(t--){
		in::read(n);
		for(int i=1;i<=n;i++)
			du[i]=0,e[i].clear();
		for(int i=1,x,y;i<n;i++)
			in::read(x,y),du[x]++,du[y]++,e[x].push_back(y),e[y].push_back(x);
		for(int i=1;i<=n;i++)if(du[i]==1){
			//1
			for(auto v:e[i]){
				printf("%d %d\n",i,v);
				e[v].erase(find(e[v].begin(),e[v].end(),i));
				e[i].erase(find(e[i].begin(),e[i].end(),v));
				break;
			}
			ans=0,val=0x3f3f3f3f; 
			dfs(i!=1?1:2,0);
			printf("%d %d\n",i,ans);
			//for(int i=1;i<=n;i++)
			//	printf("%d ",tmp[i]);
			//printf("\n");
			break;
		}
	}
	out::flush();
	return 0;
}
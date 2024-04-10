 #pragma GCC optimize(3,"Ofast","inline")
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
#define int long long
int n,a[30],S,k;
unordered_map<int,int>M[30];
int fact[1000000],Maxf;
int ans=0;
void dfs1(int now,int sum,int used){
	if(sum>S)return;// 
	if(used>k)return;
	if(now>n/2){M[used][sum]++;return;} 
	dfs1(now+1,sum,used);
	dfs1(now+1,sum+a[now],used);
	if(a[now]<=Maxf)dfs1(now+1,sum+fact[a[now]],used+1);
}void dfs2(int now,int sum,int used){
	if(sum>S)return;//
	if(used>k)return;
	if(now>n){
		for(int i=0;i<=k-used;i++)
			ans+=M[i][S-sum];
		return;
	} 
	dfs2(now+1,sum,used);
	dfs2(now+1,sum+a[now],used);
	if(a[now]<=Maxf)dfs2(now+1,sum+fact[a[now]],used+1);
}
signed main(){
	fact[1]=1;
	for(int i=2;;i++){
		if(fact[i-1]*i>1e16)break;
		fact[i]=fact[i-1]*i,Maxf=i;
	}in::read(n,k,S);
	for(int i=1;i<=n;i++)in::read(a[i]);
	dfs1(1,0,0);dfs2(n/2+1,0,0);
	out::write(ans);
	out::flush();
	return 0;
}
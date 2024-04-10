#include<bits/stdc++.h>
#define int long long
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
}
using namespace std;
int t,n,q,s;
int a[100000+10];
long long sum[100000+10];
int get(int l,int r){
	return sum[r]-sum[l-1];
}
map<long long,bool>flag;
void work(int st,int ed){
	flag[get(st,ed)]=true;
	if(a[st]==a[ed])return;
	int mid=(a[st]+a[ed])>>1;
	int sed=upper_bound(a+1,a+1+n,mid)-a-1;
	int est=sed+1;
	work(st,sed);
	work(est,ed);
}
signed main(){
	in::read(t);
	while(t--){
		in::read(n,q);
		flag.clear();
		for(int i=1;i<=n;i++)in::read(a[i]);
		sort(a+1,a+1+n);sum[0]=0;
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		work(1,n);
		for(int i=1,s;i<=q;i++){
			in::read(s);
			if(flag[i,s])puts("Yes");
			else puts("No");
		}
	}
	out::flush();
	return 0;
}
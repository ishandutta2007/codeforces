#include<bits/stdc++.h>
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
		while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
	char getC(){char c=getc();while(!isdigit(c)&&!isalpha(c))c=getc();return c;}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[25];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
#define int long long
const int N=2e5+10;
int n,a[N],b[N],ans,res;
int ed=1,q[N];
#define Y(x) b[(x)]
#define fz(x,y) (b[(x)]-b[(y)])
#define fm(x,y) ((x)-(y))
int get(int val){
	int l=2,r=ed,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(fz(q[mid],q[mid-1])<=val*fm(q[mid],q[mid-1]))
			l=mid+1,ans=mid;
		else r=mid-1;
	}return q[ans];
}
signed main(){
	in::read(n);
	for(int i=1;i<=n;i++)in::read(a[i]),b[i]=b[i-1]+a[i],ans=ans+i*a[i];
	for(int i=1;i<=n;i++){
		while(ed>1&&fz(q[ed],q[ed-1])*fm(i,q[ed])>=fz(i,q[ed])*fm(q[ed],q[ed-1]))ed--;
		q[++ed]=i;
	}
	for(int i=1;i<=n;i++){
		int j=get(a[i]);
		res=max(res,(j-i)*a[i]+b[i]-b[j]);
	}
	out::write(ans+res);
	out::flush();
	return 0;
}
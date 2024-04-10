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
}
using namespace std;
#define int long long
int t,X,Y;
 
signed main(){
	in::read(t);
	while(t--){
		in::read(X,Y);
		long long ans=0;
		int l=1,r=0x3f3f3f3f,res=1;//ans B-1  
		while(l<=r){
			int mid=l+r>>1;
			if(X/mid>=mid)res=mid,l=mid+1;
			else r=mid-1; 
		}
		res=min(res,Y);
		ans=(0+res-1)*res/2;
		for(int l=res+2,r;l<=Y+1;l=r+1){
			if(X/l==0)break;
			r=min(Y+1,X/(X/l));
			ans+=(r-l+1)*(X/l);
		}
		
		out::write(ans);
		out::putc('\n');
	}
	out::flush();
	return 0;
	//cout<<"cccccf"
}
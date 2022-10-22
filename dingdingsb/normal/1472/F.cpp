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
const int N=2e5+10;
int t,n,m;
map<int,int>s;
pair<int,int>st[N];
int r,c,cnt,f;
//1= 2= 3= 0= 
signed main(){
	in::read(t);
	while(t--){
		in::read(n,m);s.clear();
		for(int i=1;i<=m;i++)
			in::read(c,r),s[r]|=c;
		cnt=0;
		st[0]={0,3};
		for(auto x:s)
			st[++cnt]=x;//,cout<<x.first<<" "<<x.second<<endl;
		f=3;// 
		for(int i=1;i<=cnt;i++){
			if(f==3){
				//QwQ
				//
				f=st[i].second; 
			}
			else if(f==1){
				//  
				if(st[i].second==1){
					//
					if((st[i].first-st[i-1].first-1)%2==1){
						puts("NO");
						goto loop;
					}f=3;
				}else if(st[i].second==2){
					if((st[i].first-st[i-1].first)%2==1){
						puts("NO");
						goto loop;
					}f=3;
				}else{
					puts("NO");
					goto loop;
				}
			}
			else if(f==2){
				//  
				if(st[i].second==2){
					//
					if((st[i].first-st[i-1].first-1)%2==1){
						puts("NO");
						goto loop;
					}f=3;
				}else if(st[i].second==1){
					if((st[i].first-st[i-1].first)%2==1){
						puts("NO");
						goto loop;
					}f=3;
				}else{
					puts("NO");
					goto loop;
				}
			}
		}
		if(f==3)puts("YES");else puts("NO");
		loop:;
	}
	out::flush();
	return 0;
}
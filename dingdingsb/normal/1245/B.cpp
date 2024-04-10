#include<bits/stdc++.h>
namespace in{
	
	inline int getc(){return getchar();}
 
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
const int N=2000;
int t,n,a,b,c;char s[N],B[N];
signed main(){
	in::read(t);
	while(t--){
		in::read(n,a,b,c);scanf("%s",s+1);
		memset(B,0,sizeof B);int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='R'&&b){
				cnt++;B[i]='P';b--;
			}
			if(s[i]=='P'&&c){
				cnt++;B[i]='S';c--;
			}
			if(s[i]=='S'&&a){
				cnt++;B[i]='R';a--;
			}
		}
		if(cnt>=(n+1)/2){
			puts("YES");
			for(int i=1;i<=n;i++){
				if(B[i]!=0)putchar(B[i]);
				else{
					if(a)putchar('R'),a--;
					else if(b)putchar('P'),b--;
					else putchar('S'),c--;
				}
			}puts("");
		}else{
			puts("NO");
		}
	}
	out::flush();
	//cout<<"heihei";
	return 0;
}
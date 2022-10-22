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
int t,n,a[4][200];
vector<int>ans[200][4][4];
bool can[200][4][4];
signed main(){
	in::read(t);
	while(t--){
		in::read(n);
		for(int i=1;i<=n;i++)
			in::read(a[1][i]);
		for(int i=1;i<=n;i++)
			in::read(a[2][i]);
		for(int i=1;i<=n;i++)
			in::read(a[3][i]);
		memset(can,false,sizeof can);
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				if(i==j)
					can[1][i][j]=true,
					ans[1][i][j]=vector<int>(1,a[1][1]);
				else
					ans[1][i][j]=vector<int>(0);
		for(int i=2;i<=n;i++)
			for(int j=1;j<=3;j++)
				for(int st=1;st<=3;st++){
					for(int lst=1;lst<=3;lst++){
						if(can[i-1][st][lst]&&a[lst][i-1]!=a[j][i]){
							can[i][st][j]=true;
							ans[i][st][j]=ans[i-1][st][lst];
							ans[i][st][j].push_back(a[j][i]);
							break;
						}
					}
				}
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				if(can[n][i][j]&&*ans[n][i][j].begin()!=*(ans[n][i][j].end()-1)){
					for(auto a:ans[n][i][j])
						out::write(a),
						out::putc(' ');
					out::putc('\n');
					goto loop;
				}
		loop:;
	}
	out::flush();
	return 0;
}
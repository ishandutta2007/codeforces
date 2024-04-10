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
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
const int N=1e5+100;
bitset<4096>f[N];
pair<int,int>a[N][13];
int n,q,k,cnt;
signed main(){
	in::read(n,k,q);cnt=k;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			in::read(a[j][i].first),a[j][i].second=i;
	for(int i=1;i<=n;i++)sort(a[i]+1,a[i]+k+1),reverse(a[i]+1,a[i]+k+1);
	for(int i=1;i<=k;i++)
		for(int j=0;j<(1<<k);j++)
			if(j>>(i-1)&1)f[i][j]=1;
	while(q--){
		int op,x,y;in::read(op,x,y);
		if(op==1)cnt++,f[cnt]=f[x]|f[y];
		else if(op==2)cnt++,f[cnt]=f[x]&f[y];
		else{
			for(int i=1,t=0;i<=k;i++){
				t|=(1<<(a[y][i].second-1));
				if(f[x][t]){out::write(a[y][i].first);out::putc('\n');break;}
			}
		}
	}
	out::flush();
}
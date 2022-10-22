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
	char getC(){char c=getc();while(!isalpha(c))c=getc();return c;}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
	inline void puts(char *s){int now=0;while(s[now]!='\0')putc(s[now]),now++;putc('\n');}
}
using namespace std;
const int N=51,M=1e6+10;
int n,mx,a[N],ans[N][3],dp[N][M],sum,pre[N][M],flag[N];
signed main(){
	in::read(n);
	for(int i=1;i<=n;i++)in::read(a[i]),sum+=a[i],mx=max(mx,a[i]);
	for(int i=1;i<=n;i++)in::read(a[i+n]),sum+=a[i+n],mx=max(mx,a[i+n]);
	sort(a+1,a+2*n+1);
	ans[1][1]=a[1];ans[n][2]=a[2];
	sum=(sum-a[1]-a[2])/2;
	dp[0][0]=1;int m=2*n;n--;
	for(int i=3;i<=m;i++)flag[a[i]]++;
	for(int i=3;i<=m;i++)for(int j=min(i,n);j>=1;j--)for(int k=sum;k>=a[i];k--)
		if(!dp[j][k])if(dp[j-1][k-a[i]])
			pre[j][k]=a[i],dp[j][k]=1;
	for(int x=sum;x>=0;x--)
		if(dp[n][x]){
			int tp=n;
			for(int i=1;i<=n;i++)
				ans[i][2]=pre[tp][x],--flag[pre[tp][x]],x=x-pre[tp][x],--tp;
			int cnt=1;
			for(int i=0;i<=mx;i++)
				while(flag[i])
					ans[++cnt][1]=i,--flag[i];
			for(int i=1;i<=n+1;i++)out::write(ans[i][1]),out::putc(' ');out::putc('\n');
			for(int i=1;i<=n+1;i++)out::write(ans[i][2]),out::putc(' ');out::putc('\n');
			out::flush();
			return 0;
		}
}
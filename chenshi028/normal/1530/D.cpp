#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
const int o=2e5+10;
int T,n,ans,a[o],b[o],p,tp,st[o];bool vis[o];
inline void slv(){
	read(n);ans=tp=p=0;
	for(int i=1;i<=n;++i) b[i]=vis[i]=0;
	for(int i=1;i<=n;++i){read(a[i]);if(i!=a[i]&&!vis[a[i]]) vis[b[i]=a[i]]=1,++ans;}
	if(ans==n-1){
		int t1,t2;
		for(int i=1;i<=n;++i) if(!b[i]) t1=i;
		for(int i=1;i<=n;++i) if(!vis[i]) t2=i;
		if(t1==t2&&a[t1]==t1){
			if(t1==1){b[1]=2;for(int i=2;i<=n;++i) if(b[i]==2) b[i]=1;}
			else{for(int i=1;i<=n;++i) if(b[i]==1) b[i]=t1;b[t1]=1;}
			write(n-2);putchar('\n');
			for(int i=1;i<=n;++i) write(b[i]),putchar(' ');
			return;
		}
		else if(t1==t2){
			for(int i=1;i<=n;++i) if(i!=t1&&a[i]==a[t1]){b[i]=t2;b[t1]=a[t1];break;}
			write(ans);putchar('\n');
			for(int i=1;i<=n;++i) write(b[i]),putchar(' ');
			return;
		}
		write(ans);putchar('\n');
		b[t1]=t2;
		for(int i=1;i<=n;++i) write(b[i]),putchar(' ');
		return;
	}
	write(ans);putchar('\n');
	for(int i=1;i<=n;++i) if(!b[i]) st[++tp]=i;
	for(int i=1;i<=tp;++i){for(++p;vis[p];++p);b[st[i]]=p;}
	for(int i=1;i<tp;++i) if(b[st[i]]==st[i]) b[st[i]]^=b[st[i+1]]^=b[st[i]]^=b[st[i+1]];
	if(tp) if(b[st[tp]]==st[tp]) b[st[tp]]^=b[st[tp-1]]^=b[st[tp]]^=b[st[tp-1]];
	for(int i=1;i<=n;++i) write(b[i]),putchar(' ');
}
int main(){for(read(T);T--;putchar('\n')) slv();return 0;}
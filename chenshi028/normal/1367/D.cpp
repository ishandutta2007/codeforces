#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f;
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48);
}
inline int abs(int x){return x<0?-x:x;}
const int o=1e6+10;
int q,m,b[o],l,u[30],cnt;char s[o],t[o];
int main(){
	read(q);while(q--){
		scanf("%s",s+1);read(m);for(int i=1;i<=m;++i) read(b[i]);
		sort(s+1,s+1+(l=strlen(s+1)));memset(u,cnt=0,sizeof u);
		for(int i=1;i<=l;++i){++u[s[i]-96];if(s[i]^s[i-1]) t[++cnt]=s[i];}
		for(int i=1;i<=l;++i) s[i]=0;
		for(int i=cnt;i;--i){
			u[0]=0;
			for(int j=1;j<=m;++j) if(!b[j]&&!s[j]) ++u[0];
			if(u[0]>u[t[i]-96]) continue;
			for(int j=1;j<=m;++j) if(!b[j]&&!s[j]) s[j]=t[i];
			for(int j=1;j<=m;++j) if(s[j]==t[i]) for(int k=1;k<=m;++k) if(b[k]) b[k]-=abs(j-k);
		}
		for(int i=1;i<=m;++i) putchar(s[i]);
		putchar('\n');
	}
	return 0;
}
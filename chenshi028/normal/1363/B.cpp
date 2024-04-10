#include<cstdio>
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
const int o=1010;
int T,p[2][o],e[2][o],len,ans;char s[o];
inline int min(int a,int b){return a<b?a:b;}
int main(){
	read(T);while(T--){
		scanf("%s",s);ans=len=strlen(s);
		for(int i=0;i<len;++i) s[i]-=48;
		p[s[0]][0]=1;p[!s[0]][0]=0;
		for(int i=1;i<len;++i) p[s[i]][i]=p[s[i]][i-1]+1,p[!s[i]][i]=p[!s[i]][i-1];
		e[s[len-1]][len-1]=1;e[!s[len-1]][len-1]=0;e[0][len]=e[1][len]=0;
		for(int i=len-2;i+1;--i) e[s[i]][i]=e[s[i]][i+1]+1,e[!s[i]][i]=e[!s[i]][i+1];
		for(int i=1;i<=len;++i) ans=min(ans,p[0][i-1]+e[1][i]);
		for(int i=1;i<=len;++i) ans=min(ans,p[1][i-1]+e[0][i]);
		write(ans);putchar('\n');
	}
	return 0;
}
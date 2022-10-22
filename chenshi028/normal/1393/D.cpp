#include<cstdio>
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
const int o=2010;
#define int long long
inline int min(int a,int b){return a<b?a:b;}
int n,m,tmp,l[o][o],r[o][o],u[o][o],d[o][o],ans;char s[o][o],sm;
signed main(){
	read(n);read(m);
	for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
	for(int i=1;i<=m;++i){sm=0;for(int j=1;j<=n;++j) if(s[j][i]==sm) u[j][i]=j-tmp+1;else sm=s[j][i],u[tmp=j][i]=1;}
	for(int i=1;i<=m;++i){sm=0;for(int j=n;j;--j) if(s[j][i]==sm) d[j][i]=tmp-j+1;else sm=s[j][i],d[tmp=j][i]=1;}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) l[i][j]=min(min(u[i][j],d[i][j]),s[i][j]==s[i][j-1]?l[i][j-1]+1:1);
	for(int i=1;i<=n;++i) for(int j=m;j;--j) r[i][j]=min(min(u[i][j],d[i][j]),s[i][j]==s[i][j+1]?r[i][j+1]+1:1);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) ans+=min(l[i][j],r[i][j]);
	write(ans);
	return 0;
}
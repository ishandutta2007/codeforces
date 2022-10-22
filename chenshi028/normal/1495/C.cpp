#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
const int o=510;
int T,n,m;char c[o][o];
inline void upd(int col){
	for(int i=1;i<=n;++i) if(c[i][col]=='X'){c[i][col+1]='X';return;}
	for(int i=1;i<=n;++i) if(c[i][col+1]=='X'){c[i][col]='X';return;}
	c[1][col]=c[1][col+1]='X';
}
int main(){
	for(read(T);T--;){
		read(n);read(m);for(int i=1;i<=n;++i) scanf("%s",c[i]+1);
		if(m%3==1){for(int i=1;i<=m;i+=3) for(int j=1;j<=n;++j) c[j][i]='X';for(int i=2;i<m;i+=3) upd(i);}
		else{for(int i=2;i<=m;i+=3) for(int j=1;j<=n;++j) c[j][i]='X';for(int i=3;i<m;i+=3) upd(i);}
		for(int i=1;i<=n;++i,putchar('\n')) for(int j=1;j<=m;++j) putchar(c[i][j]);
	}
	return 0;
}
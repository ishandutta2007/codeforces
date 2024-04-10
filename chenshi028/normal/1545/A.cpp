#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
const int o=1e5+10;
int T,n,a[o],b[o][2];
inline void slv(){
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),b[a[i]][0]=b[a[i]][1]=0;
	for(int i=1;i<=n;++i) ++b[a[i]][i&1];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) --b[a[i]][i&1];
	for(int i=1;i<=n;++i)
		if(b[a[i]][0]||b[a[i]][1]){printf("NO");return;}
	printf("YES");
}
int main(){
	for(read(T);T--;putchar('\n')) slv();
	return 0;
}
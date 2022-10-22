#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=100;
int T,n,a[o];bool flg;
void dfs(int nw,int s,bool g){
	if(g&&!s) flg=1;
	if(nw>n) return;
	dfs(nw+1,s+a[nw],1);dfs(nw+1,s-a[nw],1);dfs(nw+1,s,g);
}
int main(){
	for(read(T);T--;printf(flg?"YES\n":"NO\n"),flg=0){
		read(n);for(int i=1;i<=n;++i) read(a[i]);dfs(1,0,0);
	}
	return 0;
}
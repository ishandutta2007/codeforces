#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
const int o=1e6+10;
int n,a[o],nxt[o],ans,l,r,lst[o];
int main(){
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),nxt[lst[a[i]]]=i,lst[a[i]]=i;nxt[0]=n+1;for(int i=1;i<=n;++i) if(!nxt[i]) nxt[i]=n+1;
	for(int i=1;i<=n;++i) if(a[i]==a[l]||a[i]==a[r]) ans+=(l!=r),l=r=i;else{++ans;if(nxt[l]<nxt[r]) l=i;else r=i;}
	write(ans);
	return 0;
}
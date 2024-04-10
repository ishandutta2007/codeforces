#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
const int o=1e5+10;
int T,n,f[o],l0[o],l1[o];char s[o],t[o];
int main(){
	for(read(T);T--;printf("%d\n",f[n])){
		read(n);scanf("%s%s",s+1,t+1);
		for(int i=1;i<=n;++i){
			if(s[i]==48||t[i]==48) l0[i]=i;
			else l0[i]=l0[i-1];
			if(s[i]==49||t[i]==49) l1[i]=i;
			else l1[i]=l1[i-1];
		}
		for(int i=1;i<=n;++i){
			f[i]=f[i-1];
			if(l0[i]) f[i]=Max(f[i],f[l0[i]-1]+1);
			if(l0[i]&&l1[i]) f[i]=Max(f[i],f[Min(l0[i],l1[i])-1]+2);
		}
	}
	return 0;
}
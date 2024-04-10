#include<cstdio>
#include<cstring>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1e5+10;
int T,ans;char s[o];
int main(){
	for(read(T);T--;printf("%d\n",ans)){
		scanf("%s",s+1);ans=0;
		for(int i=1,j=strlen(s+1);i<=j;++i) if(s[i]==48&&s[i-1]-48) ++ans;
		if(ans>2) ans=2;
	}
	return 0;
}
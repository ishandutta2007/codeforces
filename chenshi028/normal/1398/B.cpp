#include<cstdio>
#include<cstring> 
#include<algorithm>
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
const int o=110;
int T,n,cnt,a[o],lst,ans;char s[o];
int main(){
	read(T);while(T--){
		scanf("%s",s+1);n=strlen(s+1);s[n+1]=48;ans=lst=cnt=0;
		for(int i=1;i<=n+1;++i) if(s[i]==48) a[++cnt]=i-lst-1,lst=i;
		if(cnt) sort(a+1,a+1+cnt);
		for(int i=cnt;i>0;i-=2) ans+=a[i];
		write(ans);putchar('\n');
	}
	return 0;
}
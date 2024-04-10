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
const int o=2e5+10;
int T,n,ans,hd,tl,tmp;char s[o];
int main(){
	read(T);while(T--){
		read(n);scanf("%s",s+1);for(hd=1;hd<n&&s[hd+1]==s[1];++hd);for(tl=n+1;tl>hd&&s[tl-1]==s[1];--tl);
		if(tl==hd) {write((n+2)/3);putchar('\n');continue;}
		ans=(hd+n-tl+1)/3;
		for(int i=hd+1;i<=tl;++i) if(s[i]^s[i-1]) ans+=tmp/3,tmp=1;else ++tmp;
		write(ans);putchar('\n');
	}
	return 0;
}
#include<cstdio>
#include<map>
#include<utility> 
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
int T,n,a[600],b[600];bool flg;map<int,int> m1;map<pair<int,int>,int> m2;
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
int main(){
	read(T);while(T--){
		read(n);m1.clear();m2.clear();flg=0;
		for(int i=1;i<=n;++i) read(a[i]),++m1[a[i]];
		for(int i=1;i<=n;++i){read(b[i]);if(!m1[b[i]]&&!flg) printf("No\n"),flg=1;else --m1[b[i]];}
		if(flg) continue;
		if((n&1)&&(a[n/2+1]^b[n/2+1])){printf("No\n");continue;}
		for(int i=1;i<=n/2;++i) ++m2[make_pair(min(a[i],a[n-i+1]),max(a[i],a[n-i+1]))];
		for(int i=1;i<=n/2;++i){
			if(!m2[make_pair(min(b[i],b[n-i+1]),max(b[i],b[n-i+1]))]){printf("No\n");flg=1;break;}
			--m2[make_pair(min(b[i],b[n-i+1]),max(b[i],b[n-i+1]))];
		}
		if(!flg) printf("Yes\n");
	}
	return 0;
}
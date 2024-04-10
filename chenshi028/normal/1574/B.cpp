#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline int Min(int a,int b){return a<b?a:b;} 
inline int Max(int a,int b){return a>b?a:b;}
int T,a,b,c,m;
int main(){
	for(read(T);T--;){
		read(a);read(b);read(c);read(m);
		if(m<Max(c-a-b-1,Max(a-b-c-1,b-a-c-1))){printf("NO\n");continue;}
		if(c-1+a-1+b-1<m){printf("NO\n");continue;}
		printf("YES\n");continue;
	}
	return 0;
}
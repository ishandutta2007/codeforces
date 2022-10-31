#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=0;
	for(;c<='9'&&c>='0';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return f?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
//==================================================
int n,m;
inline void pr1(){
	for(int i=1;i<=m;i++){
		printf("%d",i&1?1:0);
	}
	puts("");
}
inline void pr2(){
	for(int i=1;i<=m;i++)printf("0");puts("");
}
inline void pr3(){
	printf("1");
	for(int i=2;i<m;i++)printf("0");printf("1\n");
}
int main(){
	int T=read();
	while(T--){
		n=read(),m=read();
		pr1();
		if(n&1){
			for(int i=2;i<n;i++){
				if(i&1)pr3();
				else pr2();
			}
		}
		else {
			pr2();
			for(int i=3;i<n-1;i++){
				if(i&1)pr3();
				else pr2();
			}
			pr2();
		}
		pr1();
		puts("");
	}
	return 0;
}
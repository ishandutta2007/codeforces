#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
int main(){
	int t=getint();
	while(t--){
		int n=getint(),r=getint(),b=getint();
		int k=r/(b+1),x=r%(b+1);
		for(int i=1;i<=x;++i){
			for(int j=1;j<=k+1;++j)putchar('R');
			putchar('B');
		}
		for(int i=1;i<=b-x;++i){
			for(int j=1;j<=k;++j)putchar('R');
			putchar('B');
		}
		for(int j=1;j<=k;++j)putchar('R');
		puts("");
	} 
	return 0;
}
#include<bits/stdc++.h>
#define low(x)  (x&(-(x))) //(-(a))  //2
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
//abs fabs  ab mi ma
int n,t[600020],a[600020];
char s[600020];
inline void add(int p){
	for(int i=p; i<=n; i+=low(i))++t[i];
}

inline int que(int p){
	int s=0;
	for(int i=p; i; i-=low(i))s+=t[i];
	return s;
}

int main()
{
	n=read();
	for(int i=1; i<=n; ++i)a[i]=read();
	scanf("%s",s+1);
	for(int i=1; i<=n; ++i){
		add(a[i]);
		if(s[i]==48){
			if(que(i)<i){
				puts("NO");
				exit(0);//return 0
			}//_  lo
		}
	}
	puts("YES");
	return 0;//
}
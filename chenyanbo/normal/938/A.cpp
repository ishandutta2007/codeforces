//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
char s[550];
int  a[550],n,fl;
//0123 5 50
inline int ch(int p)
{
	if(p=='y'||p=='a'||p=='e'||p=='i'||p=='o'||p=='u')return 1;
	return 0;//
}

int main()
{
	n=read();
	scanf("%s",s+1);
	for(int i=1; i<=n; ++i)a[i]=s[i];
	while(1){
		fl=0;
		for(int i=2; i<=n; ++i)if(ch(a[i])&&ch(a[i-1])){
			fl=i;
			break;
		}
		if(!fl)break;
		for(int i=fl; i<n; ++i)a[i]=a[i+1]; --n;
	}
	for(int i=1; i<=n; ++i)printf("%c",a[i]);  //strlen s+1
}
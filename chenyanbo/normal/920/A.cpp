#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;//10 -1  32 //\n//_//   eof?? E
}
int t,n,k,ma,x[505];
int main()
{
	t=read();
	while(t--){
		n=read(); k=read(); ma=0;
		for(int i=1; i<=k; ++i)x[i]=read();
		ma=max(n-x[k]+1,x[1]);
		for(int i=2; i<=k; ++i){
			ma=max(ma,(x[i]-x[i-1]+2)/2);//-9>>1//\//
		}
		printf("%d\n",ma);
	}
}
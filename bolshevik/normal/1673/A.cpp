#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int o=2e5+10;
int T,n,sm,a,b;char s[o];
int main(){
	for(scanf("%d",&T);T--;sm=a=b=0){
		scanf("%s",s+1);n=strlen(s+1);
		for(int i=1;i<=n;++i) sm+=s[i]-96;
		for(int i=2;i<=n;i+=2) a+=s[i-1]-96+s[i]-96;
		for(int i=3;i<=n;i+=2) b+=s[i-1]-96+s[i]-96;
		a=max(a,b);b=sm-a;
		if(a>b) printf("Alice %d\n",a-b);
		else printf("Bob %d\n",b-a);
	}
	return 0;
}
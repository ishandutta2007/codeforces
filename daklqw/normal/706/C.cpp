#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[2][100010],rstr[2][100010];
long long f[2][2],c[100010],t;int n,len;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&c[i]);
	f[1][0]=0;f[1][1]=c[1];
	for(int i=1;i<=n;++i){
		scanf("%s",str[i&1]);len=strlen(str[i&1]);
		for(int j=0;j<len;++j)rstr[i&1][j]=str[i&1][len-j-1];
		rstr[i&1][len]=0;
		if(i==1)continue;
		f[i&1][0]=f[i&1][1]=0x7ffffffffffffffLL;
		if(strcmp(str[i&1^1],str[i&1])<=0)f[i&1][0]=min(f[i&1][0],f[i&1^1][0]);
		if(strcmp(rstr[i&1^1],str[i&1])<=0)f[i&1][0]=min(f[i&1][0],f[i&1^1][1]);
		if(strcmp(str[i&1^1],rstr[i&1])<=0)f[i&1][1]=min(f[i&1][1],f[i&1^1][0]+c[i]);
		if(strcmp(rstr[i&1^1],rstr[i&1])<=0)f[i&1][1]=min(f[i&1][1],f[i&1^1][1]+c[i]);
	}t=min(f[n&1][0],f[n&1][1]);
	printf("%I64d\n",t==0x7ffffffffffffffLL?-1:t);
	return 0;
}
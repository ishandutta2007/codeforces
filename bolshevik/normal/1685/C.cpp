#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,pre[o],l,r;char s[o],t[o];bool flg;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%s",&n,s+1);n*=2;flg=1;
		for(int i=1;i<=n;++i) pre[i]=pre[i-1]+(s[i]=='('?1:-1);
		for(int i=1;i<=n;++i) flg&=(pre[i]>=0);
		if(flg){printf("0\n");continue;}
		for(int i=n;i;--i) if(pre[i]<0) l=i;
		for(int i=1;i<=n;++i) if(pre[i]<0) r=i+1;
		for(int i=l;i;--i) if(pre[i-1]>pre[l-1]) l=i;
		for(int i=r;i<=n;++i) if(pre[i]>pre[r]) r=i;
		for(int i=1;i<=n;++i) t[i]=s[i];
		for(int i=l,j=r;i<j;swap(t[i++],t[j--]));
		flg=1;
		for(int i=1,j=0;i<=n;++i,flg&=(j>=0)) j+=(t[i]=='('?1:-1);
		if(flg){printf("1\n%d %d\n",l,r);continue;}
		for(int i=l=1;i<=n;++i) if(pre[i]>pre[l]) l=i;
		printf("2\n%d %d\n%d %d\n",1,l,l+1,n);
	}
	return 0;
}
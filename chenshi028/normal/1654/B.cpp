#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int o=1e6+10;
int T,n,nxt[30],z[o],a;char s[o];
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%s",s+1);n=strlen(s+1);
		for(int i=0;i<26;++i) nxt[i]=0;
		for(int i=n;i;--i) z[i]=nxt[s[i]-97],nxt[s[i]-97]=i;
		for(a=1;z[a];++a);
		for(int i=a;i<=n;++i) putchar(s[i]);
	}
	return 0;
}
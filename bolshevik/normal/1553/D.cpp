#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int o=1e5+10;
int T,n,m,p;char s[o],t[o];
int main(){
	for(scanf("%d",&T);T--;printf((p>m)?"YES\n":"NO\n")){
		scanf("%s%s",s+1,t+1);n=strlen(s+1);m=strlen(t+1);
		p=1;
		for(int i=1;i<=n;++i) if(p<=m&&(((n-i)&1)==((m-p)&1))&&s[i]==t[p]) ++p;
	}
	return 0;
}
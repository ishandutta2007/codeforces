#include<cstdio>
#include<cstring>
using namespace std;
const int o=1010;
int T,n,m;char s[o],t[o];
inline void slv(){
	scanf("%s%s",s+1,t+1);n=strlen(s+1);m=strlen(t+1);
	for(int i=1,flg;i<=n&&n-i+n>=m;++i) for(int j=i;j<=n&&j-i+1<=m;++j) if(j-i+j>=m){
		flg=1;
		for(int k=i;k<=j&&flg;++k) flg=(s[k]==t[k-i+1]);
		for(int k=j-i+2;k<=m&&flg;++k) flg=(s[j-(k-(j-i+1))]==t[k]);
		if(flg){printf("YES\n");return;}
	}
	printf("NO\n");
}
int main(){
	for(scanf("%d",&T);T--;slv());
	return 0;
}
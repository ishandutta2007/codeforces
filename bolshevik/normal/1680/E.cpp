#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,f[o][2],l,r;char s[2][o];
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",min(f[r][0],f[r][1]))){
		scanf("%d%s%s",&n,s[0]+1,s[1]+1);
		for(int i=n;i;--i) if(s[0][i]=='*'||s[1][i]=='*') l=i;
		for(int i=1;i<=n;++i) if(s[0][i]=='*'||s[1][i]=='*') r=i;
		f[l][0]=f[l][1]=0;
		if(s[0][l]=='*') ++f[l][1];
		if(s[1][l]=='*') ++f[l][0];
		for(int i=l+1;i<=r;++i){
			f[i][0]=f[i-1][0]+1;f[i][1]=f[i-1][1]+1;
			if(s[0][i]=='*') ++f[i][1];
			if(s[1][i]=='*') ++f[i][0];
			f[i][0]=min(f[i][0],f[i-1][1]+2);f[i][1]=min(f[i][1],f[i-1][0]+2);
		}
	}
	return 0;
}
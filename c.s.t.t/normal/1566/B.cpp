#include<bits/stdc++.h>
using namespace std;
int T,n,res;
char s[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1),res=0;
		for(int i=1;i<=n;i++)res+=(s[i]=='0'&&s[i-1]!='0');
		res=min(res,2);
		printf("%d\n",res);
	}
	return 0;
}
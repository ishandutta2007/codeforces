#include<bits/stdc++.h>
using namespace std;
char s[111];
int main(){
	int t; cin>>t; while(t--){
		int n,a,b,c=0;
		scanf("%d%d%d%s",&n,&a,&b,s+1);
		for(int i=1;i<=n;++i)c+=s[i]!=s[i+1];
		c=c>>1;c++;
		if(b<0)printf("%d\n",a*n+b*c);
		else printf("%d\n",a*n+b*n);
	}
}
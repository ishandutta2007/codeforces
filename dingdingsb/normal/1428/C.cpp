#include<bits/stdc++.h>
using namespace std;
int t,n;char c[200000+100];
signed main(){
	scanf("%d",&t);
	while(t--) {
		scanf("%s",c+1);n=strlen(c+1);
		stack<char>s;
		for(int i=1;i<=n;i++)
			if(s.size()&&c[i]=='B')s.pop();
			else s.push(c[i]);
		printf("%d\n",s.size());
	}
	return 0;
}
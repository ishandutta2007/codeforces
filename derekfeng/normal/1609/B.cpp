#include<bits/stdc++.h>
using namespace std;
int n,q,ans,p;
char s[100004],buf[3];
int main(){
	scanf("%d%d%s",&n,&q,s+1);
	for(int i=1;i+2<=n;i++)
		if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')ans++;
	while(q--){
		scanf("%d%s",&p,buf);
		if(p>=2)if(s[p-2]=='a'&&s[p-1]=='b'&&s[p]=='c')ans--;
		if(p>=1&&p+1<=n)if(s[p-1]=='a'&&s[p]=='b'&&s[p+1]=='c')ans--;
		if(p+2<=n)if(s[p]=='a'&&s[p+1]=='b'&&s[p+2]=='c')ans--;
		s[p]=buf[0];
		if(p>=2)if(s[p-2]=='a'&&s[p-1]=='b'&&s[p]=='c')ans++;
		if(p>=1&&p+1<=n)if(s[p-1]=='a'&&s[p]=='b'&&s[p+1]=='c')ans++;
		if(p+2<=n)if(s[p]=='a'&&s[p+1]=='b'&&s[p+2]=='c')ans++;
		printf("%d\n",ans);
	}
}
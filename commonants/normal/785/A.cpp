#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
const int MX=22;
int n;

int main(){
	int ans=0;char s[MX];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		if(s[0]=='T')ans+=4;
		else if(s[0]=='C')ans+=6;
		else if(s[0]=='O')ans+=8;
		else if(s[0]=='D')ans+=12;
		else ans+=20;
	}
	printf("%d\n",ans);
	return 0;
}
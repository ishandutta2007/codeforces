#include<cstdio>
#include<iostream>
using namespace std;
int T,ans;char s[99];
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%s",s+1);ans=10;
		for(int i=1,a=0,b=0;i<=10;++i)
			if(i&1){
				if(s[i]^'?') a+=s[i]-48;
				if(a+(10-i)/2<b) ans=min(ans,i);
			}
			else{
				if(s[i]^'0') ++b;
				if(a+(11-i)/2<b) ans=min(ans,i);
			}
		for(int i=1,a=0,b=0;i<=10;++i)
			if(!(i&1)){
				if(s[i]^'?') a+=s[i]-48;
				if(a+(10-i)/2<b) ans=min(ans,i);
			}
			else{
				if(s[i]^'0') ++b;
				if(a+(11-i)/2<b) ans=min(ans,i);
			}
	}
	return 0;
}
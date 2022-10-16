#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n;
char s[1005];
int main(){
	cin>>t;
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int fg=0,qwq=0,num=0;
		for (int i=1;i<=n;i++){
			if (s[i]=='0')fg=1;
			if ((s[i]-'0')%2==0)qwq++;
			num+=s[i]-'0';
		}
		if (fg==1&&qwq>1&&num%3==0)puts("red");
		else puts("cyan");
	}
	return 0;
}
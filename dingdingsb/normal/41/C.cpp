#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
string str;
char ch[120];
bool flag=true;
signed main(){
	scanf("%s",ch);
	int len=strlen(ch+1);
	printf("%c",ch[0]);
	for(int i=1;i<len;i++){
		if(ch[i]=='a'&&ch[i+1]=='t'&&i+1!=len&&flag)str+='@',i++,flag=false;
		else if(ch[i]=='d'&&ch[i+1]=='o'&&ch[i+2]=='t'&&i+2!=len)str+='.',i+=2;
		else str+=ch[i];
	}
	cout<<str;
	printf("%c",ch[len]);
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,num;
char s[100005],sta[100005];
int top;
int main(){
	cin>>t;
	while(t--){
		scanf("%s",s+1);
		int num=0;
		top=0;
		n=strlen(s+1);
		for (int i=1;i<=n;i++){
			if (top==0)sta[++top]=s[i];
			else if (s[i]!=sta[top])--top,++num;
			else sta[++top]=s[i];
		} 
		if (num%2==1)puts("DA");
		else puts("NET");
	}
	return 0;
}
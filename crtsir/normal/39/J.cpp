#include<bits/stdc++.h>
using namespace std;
char s[1000003],t[1000003];
int main(){
	scanf("%s %s",s,t);
	int i=0,j=strlen(t)-1;
	for(;i<=j&&s[i]==t[i];i++);
	for(;j>=0&&s[j+1]==t[j];j--);
	//cout<<i<<j;
	if(i<j)cout<<0;
	else
	{
		cout<<i-j<<endl;
		for(++j;j<=i;j++)
			cout<<j+1<<' ';
	}
}
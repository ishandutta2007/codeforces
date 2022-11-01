#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[100001],ss[100001];
	scanf("%s %s",&s,&ss);
	int len=strlen(s);
	int lenn=strlen(ss);
	if(len!=lenn)cout<<max(len,lenn);
	else if(strcmp(s,ss))cout<<len<<endl;
	else cout<<"-1"<<endl;
	return 0;
}
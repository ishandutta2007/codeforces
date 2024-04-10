#include<bits/stdc++.h>
using namespace std;
char ans[1000003],s[1000003];
int main()
{
	gets(s);
	int pt=0;
	while(pt<strlen(s)&&(s[pt]=='0'||s[pt]=='.'))
		pt++;
	int u=-1;
	for(int i=0;i<strlen(s);i++)if(s[i]=='.'){u=i;break;}
	if(u==-1)u=strlen(s);
	int js=1;
	ans[0]=s[pt];
	ans[1]='.';
	for(int i=pt+1;i<strlen(s);i++)
		if(s[i]!='.')
			ans[++js]=s[i];
	pt++;
	int shift;
	if(pt==u)shift=0;
	else if(u>pt)shift=u-pt;
	else shift=u-pt+1;
	while(ans[js]=='0'||ans[js]=='.')js--;
	for(int i=0;i<=js;i++)cout<<ans[i];
	if(shift!=0)cout<<"E"<<shift;
}
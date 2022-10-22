#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,tons[3],tont[3];
char s[100010],t[100010];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		scanf("%s%s",s+1,t+1);
		int flag=1;
		for(int i=1;i<=n;++i) if(s[i]!=t[i])
		{
			if(t[i]=='a') {flag=0;break;}
			if(t[i]=='b')
			{
				if(s[i]!='a') {flag=0;break;}
				int ch=i+1;
				while(ch<=n && s[ch]=='a') ++ch;
				if(ch>n || s[ch]=='c') {flag=0;break;}
				swap(s[i],s[ch]);
			}
			else
			{
				if(s[i]!='b') {flag=0;break;}
				int ch=i+1;
				while(ch<=n && s[ch]=='b') ++ch;
				if(ch>n || s[ch]=='a') {flag=0;break;}
				swap(s[i],s[ch]);
			}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}
//ore no turn,draw!
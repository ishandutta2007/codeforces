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
const int MAXN=1e5+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n;
char s[MAXN][4];
#include<map>
map<string,int> Q1,Q2,Q3;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		int flag=0;
		for(int i=1;i<=n;++i) scanf("%s",s[i]+1);
		Q1.clear();
		Q2.clear();
		Q3.clear();
		for(int i=1;i<=n;++i)
		{
			int len=strlen(s[i]+1);
			if(len==1) {flag=1;break;}
			if(s[i][1]==s[i][len]) {flag=1;break;}
			if(len==2)
			{
				string ss="";
				ss+=s[i][1],ss+=s[i][2];
				if(Q1.find(ss)!=Q1.end()) {flag=1;break;}
				if(Q3.find(ss)!=Q3.end()) {flag=1;break;}
				swap(ss[0],ss[1]);
				Q1[ss]=1;
			}
			else
			{
				string ss="",ss2="";
				ss+=s[i][1],ss+=s[i][2],ss+=s[i][3];
				ss2+=s[i][2],ss2+=s[i][3];
				if(Q2.find(ss)!=Q2.end()) {flag=1;break;}
				if(Q1.find(ss2)!=Q1.end()) {flag=1;break;}
				swap(ss[0],ss[2]);
				Q2[ss]=1;
				ss2[0]=s[i][2],ss2[1]=s[i][1];
				Q3[ss2]=1;
			}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}
//ore no turn,draw!
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,l[4000005];
char s1[1000005],s2[1000005],s[4000005];
char cha(char c)
{
	if(c=='W')return 'E';
	if(c=='E')return 'W';
	if(c=='N')return 'S';
	if(c=='S')return 'N';
}

void manacher()
{
	int mx=0,id=0;
	for(int i=1;i<=m;i++)
	{
		if(mx>i)l[i]=min(l[id+id-i],mx-i);
		for(;i-l[i]>0&&i+l[i]<=m&&s[i+l[i]]==s[i-l[i]];l[i]++);
		if(i+l[i]>mx)
			mx=i+l[i],id=i;
	}
}

int main()
{
	scanf("%d",&n);n--;
	scanf("%s%s",s1+1,s2+1);
	for(int i=1;i<=n;i++)
		s1[i]=cha(s1[i]);
	reverse(s2+1,s2+n+1);
	m=0;
	s[++m]='#';
	for(int i=1;i<=n;i++)
	{
		s[++m]=s1[n-i+1];
		s[++m]='#';
		s[++m]=s2[i];
		s[++m]='#';
	}
	manacher();
	for(int i=3;i<=m;i+=2)
		if(i-l[i]<=0){puts("NO");return 0;}
	puts("YES");
	return 0;
}
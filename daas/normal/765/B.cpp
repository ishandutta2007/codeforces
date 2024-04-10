#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int pd[26],len;
char s[501];
int main()
{
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;i<len;++i)
	{
		int c=s[i]-'a';
		if(pd[c])
			continue;
		for(int j=0;j<c;++j)
			if(!pd[j])
			{
				puts("NO");
				return 0;
			}
		pd[c]=1;
	}
	puts("YES");
	return 0;
}
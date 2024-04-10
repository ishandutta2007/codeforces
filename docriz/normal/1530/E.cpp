#include<bits/stdc++.h>
using namespace std;
int T,buc[26],n,num,cnt=0;
char s[100005],t[100005];
int fd(int x=-1,int y=-1)
{
	for(int i=0;i<26;i++)
	{
		if(i==x||i==y)continue;
		if(buc[i])return i;
	}
}
void cons(int x)
{
	t[cnt++]=x+'a';
	buc[x]--;
}
void opt1(int x)
{
	cons(x);
	for(int i=1;i<n;i++)cons(fd());
}
void opt2(int x)
{
	cons(x);
	cons(x);
	for(int i=2;i<n;i++)
	{
		if(t[i-1]-'a'==x)cons(fd(x));
		else cons(fd());
	}
}
void optall(int x)
{
	for(int i=0;i<n;i++)t[i]='a'+x;
}
void opt2z(int x,int y)
{
	cons(x);
	for(int i=1;i<n;i++)
	{
		if(buc[y])cons(y);
		else cons(x);
	}
}
void opt3(int x,int y)
{
	cons(x);
	cons(y);
	for(int i=2;i<n;i++)
	{
		if(t[i-1]-'a'==x)cons(fd(y));
		else cons(fd());
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;
		num=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(buc,0,sizeof(buc));
		for(int i=1;i<=n;i++)buc[s[i]-'a']++;
		for(int i=0;i<26;i++)if(buc[i])num++;
		int bt=-1;
		for(int i=0;i<26;i++)
		{
			if(buc[i]==1)
			{
				bt=i;
				break;
			}
		}
		if(bt!=-1)
		{
			opt1(bt);
			goto tag;
		}
		for(int i=0;i<26;i++)
		{
			if(buc[i])
			{
				bt=i;
				break;
			}
		}
		if(n-buc[bt]>=buc[bt]-2)opt2(bt);
		else
		{
			if(num==1)optall(bt);
			else
			{
				int bt2=-1;
				for(int i=bt+1;i<26;i++)
				{
					if(buc[i])
					{
						bt2=i;
						break;
					}
				}
				if(num==2)opt2z(bt,bt2);
				else opt3(bt,bt2);
			}
		}
		tag:;
		t[n]=0;
		printf("%s\n",t);
	}
	return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
#include<map>
using namespace std;
int n,m,b;
deque<int>q;
map<int,int>low,tmp;
char s[10];
void print(map<int,int>cur)
{
	for(int i=m-1;~i;--i)putchar(cur[i]^48);
	putchar('\n');
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)q.push_back(i);
	b=m;
	while(b+(int)q.size()!=1)
	{
		tmp=low;
		for(int i=0;i<b-1;++i)tmp[i]=1;
		printf("%d ",q.back());print(tmp);
		fflush(stdout);
		scanf(" %s",s);
		if(s[0]=='n')
		{
			int a=q.back();q.pop_back();
			q.push_front(a);--b;
		}
		else
		{

			for(int i=b-1;;++i)
			{
				if(low[i])q.pop_front(),++b,low[i]=0;
				else {low[i]=1;break;}
			}
		}
	}
	printf("0 ");
	print(low);fflush(stdout);
	return 0;
}
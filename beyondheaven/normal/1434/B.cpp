#include<bits/stdc++.h>
#define MaxN 200123
int n;
char opt[MaxN];
int x[MaxN];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;++i)
	{
		do scanf("%c",opt+i);
		while(opt[i]!='+'&&opt[i]!='-');
		
		if(opt[i]=='-')
		scanf("%d",x+i);
	}
	
	int cnt=0;
	for(int i=1;i<=2*n;++i)
	{
		if(opt[i]=='+')++cnt;
		else if(cnt==0)
		{
			puts("NO");
			return 0;
		}
		else --cnt;
	}
	
	for(int i=1;i<=2*n;)
	{
		if(opt[i]=='+')
		{
			++i;
			continue;
		}
		int j=i;
		while(opt[j+1]=='-')++j;
		for(int k=i;k<j;++k)
		if(x[k]>x[k+1])
		{
			puts("NO");
			return 0;
		}
		i=j+1;
	}
	
	std::vector<int>s;
	
	for(int i=1;i<=2*n;++i)
	{
		if(opt[i]=='+')
		s.push_back(i);
		else
		{
			x[s.back()]=x[i];
			s.pop_back();
		}
	}
	
	std::priority_queue<int,std::vector<int>,std::greater<int>>q;
	
	for(int i=1;i<=2*n;++i)
	{
		if(opt[i]=='+')q.push(x[i]);
		else
		{
			if(q.top()!=x[i])
			{
				puts("NO");
				return 0;
			}
			q.pop();
		}
	}
	puts("YES");
	for(int i=1;i<=2*n;++i)
	if(opt[i]=='+')
	printf("%d ",x[i]);
	puts("");
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,s;
long long f[65];
struct str{
	int c;
	long long x,y;
};
vector<str> g,ans;
bool Insert(long long x)
{
	for(i=40;i>=0;--i)
		if((x>>i)&1)
			if(!f[i])
			{
				f[i]=x;
				return true;
			}
			else
			{
				g.push_back((str){2,x,f[i]});
				x^=f[i];
			}
	return false;	
}
int main()
{
	scanf("%d",&n);
	Insert(n);
	g.push_back((str){2,n,n});
	int sum=0;
	while(1)
	{
		g.clear();
		long long s=0,s2=0;
		for(i=39;i>=0;--i)
			if(rand()&1)
			{
				g.push_back((str){2,s,f[i]});
				s^=f[i];
			}
		for(i=39;i>=0;--i)
			if(rand()&1)
			{
				g.push_back((str){2,s2,f[i]});
				s2^=f[i];
			}
		g.push_back((str){1,s,s2});
		if(Insert(s+s2))
			for(auto it:g)
				ans.push_back(it);
		if(f[0])
			break;
	}
	int sm=0;
	for(auto it:ans)
		if(it.x!=0&&it.y!=0)
			++sm;
	printf("%d\n",sm);
	for(auto it:ans)
		if(it.x!=0&&it.y!=0)
			printf("%lld %c %lld\n",it.x,(it.c==1?'+':'^'),it.y);
}
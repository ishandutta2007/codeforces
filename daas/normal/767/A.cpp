#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<set>
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
int n,last;
set<int> Q;
int main()
{
	last=n=read();
	for(int i=1;i<=n;++i)
	{
		int v=read();
		Q.insert(v);
		set<int> :: iterator id=Q.end();
		--id;
		while((*id)==last)
		{
			printf("%d ",(*id));
			last--;
			Q.erase(id);
			if(Q.empty())
				break;
			id=Q.end();
			--id;
		}
		putchar('\n');
	}
	return 0;
}
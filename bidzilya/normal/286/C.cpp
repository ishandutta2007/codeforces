#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

typedef long long ll;

int n,t;
vector<int> a;
stack<pair<int,int> > s;

int rebuild(int neg=1)
{
	stack<int> t;
	pair<int,int> tmp=s.top();
	s.pop();
	if (!neg)a[tmp.second]*=-1;
	t.push(tmp.first);
	while (s.size())
	{
		tmp=s.top();
		s.pop();
		if (tmp.first==t.top())
		{
			t.pop();
			if (t.size()==0)
				return 1;
		}else
		{
			t.push(tmp.first);
			a[tmp.second]*=-1;
		}
	}
	return 0;
}	

int main()
{
	//freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	a.resize(n+1);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	scanf("%d",&t);
	for (int i=0; i<t; i++)
	{
		int x;
		scanf("%d",&x);
		a[x]*=-1;
	}
	pair<int,int>tmp;
	for (int i=1; i<=n; i++)
		if (a[i]<0)
		{
			if (s.size() && s.top().first+a[i]==0)
				s.pop();
			else
			{
				s.push(pair<int,int>(abs(a[i]),i));
				if (!rebuild())
				{
					printf("NO\n");
					return 0;
				}
			}
		}else
			s.push(pair<int,int>(a[i],i));
	while (s.size())
		if (!rebuild(0))
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	for (int i=1; i<=n; i++)
		printf("%d ",a[i]);	
	printf("\n");
	return 0;
}
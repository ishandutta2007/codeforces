#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;
	scanf("%d",&x);
	return x;
}
int main()
{
	int n=read(),m=0;
	for(int i=1; i<=n; i++)
	{
		int t=read();
		t+=m;
		printf("%d ",t);
		m=max(m,t);
	}
	return 0;
}
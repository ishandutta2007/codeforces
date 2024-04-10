#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,v,tot;
	scanf("%d%d",&n,&v);
	if(n-1<v) 
	{
		cout<<n-1;
		return 0;
	}
	tot=v-1+((n-v)*(n-v+1)/2);
	cout<<tot;
	return 0;
}
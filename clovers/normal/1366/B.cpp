#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int n,m,x,t;

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&m);
		int nowl=x,nowr=x;
		for(int i=1;i<=m;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(r>=nowl&&l<nowl) nowl=l;
			if(l<=nowr&&r>nowr) nowr=r;
		} 
		printf("%d\n",nowr-nowl+1);
	}
	return 0;
}
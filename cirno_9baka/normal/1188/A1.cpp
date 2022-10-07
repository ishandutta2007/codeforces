#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const ll M=1000000007;
const int N=500005;
int i,n,u,v,s,d[N];
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		d[u]++;
		d[v]++;
	}
	for(i=1;i<=n;i++)
		if(d[i]==2)
		{
			printf("NO");
			return 0;
		}
	printf("YES");
}
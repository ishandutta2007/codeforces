#include<bits/stdc++.h>
using namespace std;
vector<int> a[100003];
int u[100003],v[100003];
int main()
{
	int n,k=-1;
	scanf("%d",&n);
	for(int i=1; i<n; i++) scanf("%d%d",&u[i],&v[i]),a[u[i]].push_back(v[i]),a[v[i]].push_back(u[i]);
	for(int i=1; i<=n; i++) if(a[i].size()>2) 
	{
		k=i;
		break;
	}
	if(k==-1) 
	{
		for(int i=1; i<n; i++) printf("%d\n",i-1);
		return 0;
	}
	int now=3;
	for(int i=1; i<n; i++) if(u[i]==k)
	{
		if(v[i]==a[k][0]) printf("0\n");
		else if(v[i]==a[k][1]) printf("1\n");
		else if(v[i]==a[k][2]) printf("2\n");
		else printf("%d\n",now++);
	 } 
	 else if(v[i]==k)
	 {
	 	if(u[i]==a[k][0]) printf("0\n");
		else if(u[i]==a[k][1]) printf("1\n");
		else if(u[i]==a[k][2]) printf("2\n");
		else printf("%d\n",now++);
	 }
	 else printf("%d\n",now++);
	return 0;
}
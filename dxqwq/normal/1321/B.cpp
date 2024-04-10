#include<bits/stdc++.h>
#include<map>
using namespace std;
int a[500003],b[500003];
bool f[500003];
using namespace std;
map<int,int> M;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=n; i++) 
	{
		map<int,int>::iterator m;
    	m=M.find(a[i]-i);
    	if(m!=M.end()) b[m->second]=i,f[i]=1,M.erase(m);
		M[a[i]-i]=i;
	}
	long long ans=0,now;
	int pos;
	for(int i=1; i<=n; i++) if(!f[i]) 
	{
		now=a[i],pos=i;
		while(b[pos]) pos=b[pos],now+=a[pos];
		if(now>ans) ans=now;
	}
	cout<<ans;
	return 0;
}
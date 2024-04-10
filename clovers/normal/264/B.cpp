#include<bits/stdc++.h>
using namespace std;
const int N=150005;
int bl[N],prime[N],tot=0,n;
int mx[N],a[N];
void init()
{
	for(int i=1;i<=150000;i++) bl[i]=1;
	bl[1]=0;
	for(int i=2;i<=150000;i++)
	{
		if(bl[i]) prime[++tot]=i;
		for(int j=i+i;j<=150000;j+=i) bl[i]=0;
	}
}

int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(mx,0,sizeof(mx));
	for(int i=1;i<=n;i++)
	{
		int maxx=0;
		vector<int> v; v.clear();
		for(int j=1;prime[j]*prime[j]<=a[i];j++)
		{
		//	cout<<prime[j]<<endl;
			if(a[i]%prime[j]==0) 
			{
				maxx=max(mx[prime[j]]+1,maxx);
				v.push_back(prime[j]);
			}
			while(a[i]%prime[j]==0) a[i]/=prime[j];
		}
		if(a[i]>1) maxx=max(mx[a[i]]+1,maxx);
		v.push_back(a[i]);
		//cout<<maxx<<endl;
		for(int j=0;j<(int)v.size();j++) mx[v[j]]=maxx;
	}
	int ans=1;
	for(int i=1;i<=tot;i++) ans=max(ans,mx[prime[i]]);
	cout<<ans<<endl;
}
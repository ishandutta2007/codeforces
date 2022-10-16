#include<bits/stdc++.h>
using namespace std;
#define N 1111
int a[N]={0};
int p[N];
int plen=0;
int main()
{
	for(int i=2;i<N;i++)if(!a[i])
	{
		p[plen++]=i;
		for(int j=i+i;j<N;j+=i) a[j]=1;
	}
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=0;p[i]+p[i+1]+1<=n;i++)
		if(!a[p[i]+p[i+1]+1])ans++;//,cout<<p[i]+p[i+1]+1<<endl;
	if(ans>=k)
		cout<<"YES";
	else
		cout<<"NO";
}
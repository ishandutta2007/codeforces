#include<bits/stdc++.h>
using namespace std;
int n,a[105],i,j,l[105],g[105][105],t,k,p;
bool cmp(int a,int b)
{
	cout<<1<<' '<<a<<' '<<b<<endl;
	int t;
	cin>>t;
	return t;
}
int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
			a[i]=i;
		memset(g,0,sizeof(g));
		stable_sort(a,a+n,cmp);
		l[n]=n-1;
		for(i=n-1;i>=0;--i)
		{
			l[i]=min(l[i+1],i-1);
			while(l[i]>=0)
			{
				cout<<2<<' '<<a[i]<<' '<<l[i]+1<<' ';
				for(j=l[i];j>=0;--j)
					cout<<a[j]<<' ';
				cout<<endl;
				int t;
				cin>>t;
				if(t==-1)
					while(1);
				if(t==0)
					break;
				--l[i];
			}
		}
		for(i=n-1;i>=0;)
		{
			int mn=l[i];
			for(j=i;j>mn;--j)
				mn=min(mn,l[j]);
			for(k=i;k>j;--k)
				for(p=i;p>=0;--p)
					g[a[p]][a[k]]=1;
			i=j;
		}
		cout<<3<<endl;
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
				cout<<g[i][j];
			cout<<endl;
		}
		cout<<endl;
		int t;
		cin>>t;
	}
}
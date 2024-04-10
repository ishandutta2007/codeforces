#include<bits/stdc++.h>
using namespace std;
const int M=31607,L=5000,N=10005;
int n,k,i,t,m,j,p[N],q[N],kp,kq,s;
char a[N],b[N];
struct str{
	int l,r;
};
vector<str> ans,ans1;
void MV(int *a,int x,int y,int z)
{
	int i;
	if(x<y)
	{
		int s1=0,s2=0;
		for(i=1;i<=x;++i)
			s1+=a[i]+1;
		for(i=1;i<y;++i)
			s2+=a[i]+1;
		ans.push_back({s1-z,s2});
	}
	else
	{
		int s1=0,s2=0;
		for(i=1;i<=y;++i)
			s1+=a[i]+1;
		for(i=1;i<x;++i)
			s2+=a[i]+1;
		ans.push_back({s1,s2+z});
	}
	a[x]-=z;
	a[y]+=z;
	int t=max(x,y);
	x=min(x,y);
	y=t;
//	cout<<x<<' '<<y<<endl;
	if(x+1<=y-1)
	{
//		cout<<x+1<<' '<<y-1<<endl;
//		cout<<a[2]<<' '<<a[3]<<endl;
		reverse(a+x+1,a+y);
//		cout<<a[2]<<' '<<a[3]<<endl;
	}
}
void Deal(int *a)
{
	int i;
	if(k==0||n<=k)
		return;
	if(n==k+1)
	{
		MV(a,n,1,a[n]);
//		for(i=1;i<=n;++i)
//			cout<<a[i]<<' ';
//		cout<<endl;
		if(n>=4)
		{
			for(i=2;i<=n/2;++i)
			{
				if(a[i]>a[n-i+1])
				{
//					cout<<i<<endl;
					MV(a,1,n,0);
					break;
				}
				if(a[i]<a[n-i+1])
					break;
			}
		}
//		for(i=1;i<=n;++i)
//			cout<<a[i]<<' ';
//		cout<<endl;
		return;
	}
	if(k&1)
	{
		for(i=n;i>=k+2;--i)
			MV(a,i,i-k,a[i]);
		for(i=1;i<=k;++i)
		{
			MV(a,k+1,1,a[k+1]);
			MV(a,2,k+2,0);
		}
	}
	else
	{
		for(i=n;i>k+2;--i)
			MV(a,i,i-k,a[i]);
		for(i=1;i<=(k+1);++i)
		{
			MV(a,k+1,1,a[k+1]);
			MV(a,2,k+2,a[2]);
		}
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		scanf("%s",a+1);
		scanf("%s",b+1);
		kp=s=0;
		for(i=1;i<=n;++i)
		{
			if(a[i]=='0')
				++s;
			if(a[i]=='1')
			{
				p[++kp]=s;
				s=0;
			}
		}
		p[++kp]=s;
		kq=s=0;
		for(i=1;i<=n;++i)
		{
			if(b[i]=='0')
				++s;
			if(b[i]=='1')
			{
				q[++kq]=s;
				s=0;
			}
		}
		q[++kq]=s;
		if(kp!=kq)
		{
			puts("-1");
			continue;
		}
		n=kp;
		ans.clear();
		Deal(p);
		ans1=ans;
		ans.clear();
		Deal(q);
		reverse(ans.begin(),ans.end());
//		for(i=1;i<=n;++i)
//			cout<<p[i]<<' ';
//		cout<<endl;
//		for(i=1;i<=n;++i)
//			cout<<q[i]<<' ';
//		cout<<endl;
		for(i=1;i<=n;++i)
			if(p[i]!=q[i])
				break;
		if(i<=n)
		{
			puts("-1");
			continue;
		}
		printf("%d\n",ans.size()+ans1.size());
		for(auto it:ans1)
			printf("%d %d\n",it.l,it.r);
		for(auto it:ans)
			printf("%d %d\n",it.l,it.r);
	}
}
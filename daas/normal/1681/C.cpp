#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,a[200],b[200];
vector<pair<int,int> > ans;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i) b[i]=read();
		ans.clear();
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				if(a[j]<a[i] || (a[j]==a[i] && b[j]<b[i]))
				{
					swap(a[i],a[j]);
					swap(b[i],b[j]);
					ans.push_back(make_pair(i,j));
				}
			}
		}
		int flag=1;
		for(int i=2;i<=n;++i) if(b[i]<b[i-1]) flag=0;
		if(!flag) {puts("-1");continue;}
		printf("%d\n",(int)ans.size());
		for(int i=0;i<(int)ans.size();++i) printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}
//ore no turn,draw!
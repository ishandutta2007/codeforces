#include<bits/stdc++.h>
using namespace std;
int n,p[16],i,j;
struct str{
	int u,v;
};
vector<str> ans;
void cal(vector<int> p)
{
	int i,j;
	if(p.size()==5)
	{
		ans.push_back({p[0],p[4]});
		ans.push_back({p[0],p[1]});
		ans.push_back({p[1],p[4]});
		ans.push_back({p[2],p[4]});
		ans.push_back({p[2],p[3]});
		ans.push_back({p[3],p[4]});
		ans.push_back({p[0],p[2]});
		ans.push_back({p[1],p[3]});
		ans.push_back({p[0],p[3]});
		ans.push_back({p[1],p[2]});
	}
	if(p.size()==8)
	{
		for(i=0;i<4;++i)
			ans.push_back({p[i],p[(i+1)%4+4]});
		for(i=0;i<4;++i)
			ans.push_back({p[i],p[(i+3)%4+4]});
		for(i=0;i<4;++i)
			ans.push_back({p[i],p[(i+2)%4+4]});
		for(i=0;i<4;++i)
			ans.push_back({p[i],p[i+4]});
	}
	if(p.size()==4)
	{
		ans.push_back({p[0],p[1]});
		ans.push_back({p[1],p[3]});
		ans.push_back({p[0],p[2]});
		ans.push_back({p[1],p[2]});
		ans.push_back({p[0],p[3]});
		ans.push_back({p[2],p[3]});
	}
}
int main()
{
	scanf("%d",&n);
	if(n%4==2||n%4==3)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	if(n%4==0)
		for(i=1;i<=n;i+=4)
		{
			vector<int> p={i,i+1,i+2,i+3};
			cal(p);
			for(j=i+4;j<=n;j+=4)
			{
				vector<int> p={i,i+1,i+2,i+3,j,j+1,j+2,j+3};
				cal(p);
			}
		}
	if(n%4==1)
		for(i=1;i<n;i+=4)
		{
			vector<int> p={i,i+1,i+2,i+3,n};
			cal(p);
			for(j=i+4;j<n;j+=4)
			{
				vector<int> p={i,i+1,i+2,i+3,j,j+1,j+2,j+3};
				cal(p);
			}
		}
	for(auto it:ans)
		printf("%d %d\n",it.u,it.v);
}
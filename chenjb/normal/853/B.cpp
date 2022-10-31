/* suck it!!!!!!!! */
#include<bits/stdc++.h>
using namespace std;
long long v1[110000];
long long v2[110000];
int n,m,k;
struct pp
{
	int id;
	long long cost;
	int d;
};
vector<pp> t1;
vector<pp> t2;
bool cmp1(pp x,pp y)
{
	return x.d<y.d;
}
bool cmp2(pp x,pp y)
{
	return x.d>y.d;
}
long long ans1[2100000];
long long ans2[2100000];
int main()
{
	memset(ans1,-1,sizeof(ans1));
	memset(ans2,-1,sizeof(ans2));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int d,f,t,c;
		scanf("%d%d%d%d",&d,&f,&t,&c);
		if(t==0)
		{
			t1.push_back((pp){f,c,d});
		}
		else
		{
			t2.push_back((pp){t,c,d});
		}
	}
	sort(t1.begin(),t1.end(),cmp1);
	sort(t2.begin(),t2.end(),cmp2);
	long long tt=0;
	int cnt=0;
	for(auto &i:t1)
	{
		int id=i.id;
		long long cc=i.cost;
		int dd=i.d;
		//cout<<id<<" "<<cc<<" "<<dd<<endl;
		if(v1[id]==0)
		{
			cnt++;
			tt+=cc;
			v1[id]=cc;
		}
		else
		{
			if(cc<v1[id])
			{
				tt-=v1[id];
				tt+=cc;
				v1[id]=cc;
			}
		}
		if(cnt==n)
		{
			//cout<<dd<<" "<<tt<<endl;
			ans1[dd]=tt;
		}
	}
	//cout<<"******"<<endl;
	cnt=0;
	tt=0;
	for(auto &i:t2)
	{
		int id=i.id;
		long long cc=i.cost;
		int dd=i.d;
		//cout<<id<<" "<<cc<<" "<<dd<<endl;
		if(v2[id]==0)
		{
			cnt++;
			tt+=cc;
			v2[id]=cc;
		}
		else
		{
			if(cc<v2[id])
			{
				tt-=v2[id];
				tt+=cc;
				v2[id]=cc;
			}
		}
		if(cnt==n)
		{
			//cout<<dd<<" "<<tt<<endl;
			ans2[dd]=tt;
		}
	}
	for(int i=1;i<=1000000;i++)
	{
		if(ans1[i]==-1) ans1[i]=ans1[i-1];
	}
	for(int i=1000000;i>=1;i--)
	{
		if(ans2[i]==-1) ans2[i]=ans2[i+1];
	}
	long long ans=-1;
	for(int i=1;i<=1000000;i++)
	{
		long long x=ans1[i];
		long long y=ans2[i+k+1];
		if(x==-1||y==-1) continue;
		if(ans==-1) ans=x+y;
		else ans=min(ans,x+y);
	}
	printf("%lld\n",ans);
	return 0;
}
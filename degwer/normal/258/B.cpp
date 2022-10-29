#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll dat[11];
ll dp[11][11][2];
void calc(int num)
{
	vector<int>vec;
	for(;;)
	{
		if(num==0)
		{
			break;
		}
		vec.push_back(num%10);
		num/=10;
	}
	reverse(vec.begin(),vec.end());
	dp[0][0][0]=1;
	for(int i=1;i<=vec.size();i++)
	{
		for(int j=0;j<=vec.size();j++)
		{
			dp[i][j][1]+=dp[i-1][j][1]*8;
			if(j!=0)
			{
				dp[i][j][1]+=dp[i-1][j-1][1]*2;
			}
			for(int k=0;k<10;k++)
			{
				if(vec[i-1]>k)
				{
					if(k==4||k==7)
					{
						dp[i][j][1]+=dp[i-1][j-1][0];
					}
					else
					{
						dp[i][j][1]+=dp[i-1][j][0];
					}
				}
				if(vec[i-1]==k)
				{
					if(k==4||k==7)
					{
						dp[i][j][0]+=dp[i-1][j-1][0];
					}
					else
					{
						dp[i][j][0]+=dp[i-1][j][0];
					}
				}
			}
		}
	}
	for(int i=0;i<=vec.size();i++)
	{
		dat[i]=dp[vec.size()][i][0]+dp[vec.size()][i][1];
	}
	dat[0]--;
}
ll po(ll a,ll b)
{
	vector<int>vec;
	for(;;)
	{
		if(b==0)
		{
			break;
		}
		vec.push_back(b%2);
		b/=2;
	}
	reverse(vec.begin(),vec.end());
	ll ret=1;
	for(int i=0;i<vec.size();i++)
	{
		ret*=ret;
		ret%=mod;
		if(vec[i])
		{
			ret*=a;
			ret%=mod;
		}
	}
	return ret;
}
ll inv(ll a)
{
	return po(a,mod-2);
}
ll kai[100001];
void calckai()
{
	kai[0]=1;
	for(int i=1;i<=100000;i++)
	{
		kai[i]=kai[i-1]*i;
		kai[i]%=mod;
	}
}
ll com(ll a,ll b)
{
	ll ret=kai[a];
	ret*=inv(kai[b]);
	ret%=mod;
	ret*=inv(kai[a-b]);
	ret%=mod;
	return ret;
}
ll ans=0;
void calcans(vector<int>vec,ll tim)
{
	ll ret=1;
	ll tim2=1;
	ll rem=6;
	for(int i=0;i<vec.size();i++)
	{
		for(int j=1;j<=vec[i];j++)
		{
			ret*=(dat[i]-j+1);
			ret%=mod;
		}
		if(vec[i]!=0)
		{
			tim2*=com(rem,vec[i]);
			tim2%=mod;
			rem-=vec[i];
		}
	}
	ret*=tim2;
	ret%=mod;
	ans+=(ret*tim)%mod;
	ans%=mod;
}
void solve(int nowsum,int now,int mok,vector<int>vec,ll tim,int gou)
{
	if(nowsum>=mok||gou>6)
	{
		return;
	}
	if(now==10&&gou==6)
	{
		calcans(vec,tim);
		return;
	}
	if(now==10&&gou!=6)
	{
		return;
	}
	for(int i=0;i<=min(6LL,dat[now]);i++)
	{
		vec.push_back(i);
		solve(nowsum+i*now,now+1,mok,vec,tim,gou+i);
		vec.pop_back();
	}
}
int main()
{
	int num;
	scanf("%d",&num);
	calc(num);
	calckai();
	for(int i=1;i<=9;i++)
	{
		if(dat[i]==0)
		{
			continue;
		}
		dat[i]--;
		vector<int>damy;
		solve(0,0,i,damy,dat[i]+1,0);
		dat[i]++;
	}
	printf("%I64d\n",ans);
}
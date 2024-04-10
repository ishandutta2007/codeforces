#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_lcm=2520;
int dig[25];
int Hash[2525];
ll dp[25][50][2525];

ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return a/gcd(a,b)*b;
}
ll dfs(int len,int pre_lcm,int pre_num,int flag)
{
	if(len==0)
	{
		return pre_num % pre_lcm ==0;
	}
	if(!flag && dp[len][ Hash[pre_lcm] ][pre_num]!= -1 )
	return dp[len][ Hash[pre_lcm] ][pre_num];
	int n = flag ? dig[len] : 9;
	ll res = 0;
	for(int i=0;i<=n;i++)
	{
		int now_num = (pre_num * 10 +i) % max_lcm;
		int now_lcm = pre_lcm;
		if(i) now_lcm = lcm(pre_lcm,i);
		res += dfs(len-1,now_lcm,now_num,flag&&i==n);
	}
	if(!flag){
		dp[len][Hash[pre_lcm]][pre_num] = res;
	}
	return res;
}
ll cal(ll num)
{
	int len=0;
	while(num)
	{
		dig[++len]=num%10;
		num/=10;
	}
	return dfs(len,1,0,1);
}

int main()  
{  
	//freopen("in.txt","r",stdin);
	int t;
	ll a,b;
	int cnt=0;
	for(int i=1;i<=2520;i++)
	{
		if(max_lcm%i==0){
			Hash[i]=++cnt;
		}
	}
	cin>>t;
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		scanf("%I64d %I64d",&a,&b);
		//cout<<cal(b)-cal(a-1)<<endl;
		printf("%I64d\n",cal(b)-cal(a-1));
	}
    return 0;  
}
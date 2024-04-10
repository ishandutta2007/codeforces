#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#pragma G++ optimize ("O3")
typedef long long ll;
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
deque<pair<int,int>>q;
ll n,k,m;
ll dfs(ll sum)
{
	if(q.empty()){
		return 0;
	}
	else if(q.size()==1)
	{
		ll ans = (q.front().second * m)%k;
		return ans;
	}
	else if(q.front().first!=q.back().first)
	{
		ll ans =sum *m;
		return ans;
	}
	else if((q.front().second+q.back().second) % k > 0)
	{
		ll tmp=(q.front().second + q.back().second) / k * k;
		return sum * m - tmp * (m-1);
	}
	else{
		ll a=q.front().second; q.pop_front();
		ll b=q.back().second; q.pop_back();
		ll ans=dfs(sum-a-b);
		if(ans==0){
			return (a+b)%k;
		}
		else{
			return ans+a+b;
		}
	}
}
int main()
{ 
	//ios::sync_with_stdio(0);
//	cin.tie(0);
	int t;
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
	{
		t=read();
		if(q.empty() || q.back().first!=t)
		{
				q.push_back(make_pair(t,1));
		}
		else
		{
			q.back().second ++;
			if(q.back().second == k)
			{
				q.pop_back();
			}
		}
	}
	ll sum=0;
	for(auto&& x:q){
		sum += x.second;
	}	
	if(m==1)
	{
		cout<<sum<<endl;
		exit(0);
	}
	ll ans=dfs(sum);
	cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
int n;
ll dif[200005];
int sch(ll arr[],ll one,int bg)
{
	int ind=upper_bound(arr+bg,arr+n,-one)-arr;
	return n-ind;
}
ll solve()
{
	sort(dif,dif+n);
	ll ans=0;
	rep(i,n)
	{
		ans+=sch(dif,dif[i],i+1);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	rep(i,n) cin>>dif[i];
	rep(i,n) {ll k;cin>>k;dif[i]-=k;}
	cout<<solve()<<endl;
	return 0;
} 
/*
7
-3 -4 3 -1 2 0 0
0 0 0 0 0 0 0
*/
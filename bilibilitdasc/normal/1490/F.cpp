#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//cin
int n;
map<int,int> cnt;
void solve()
{
	cin>>n;cnt.clear();
	int notdelete=0,ans;
	rep(i,n)
	{
		int a;
		cin>>a;
		cnt[a]++;
	}
	vector<int> num;
	for(map<int,int>::iterator itr=cnt.begin();itr!=cnt.end();itr++)
	{
		num.pb(itr->second);
	}
	sort(num.begin(),num.end());
	#if 0
	rep(i,have.size()) cout<<cnt[i]<<' ';
	cout<<endl;
	#else
	for(int i=1;i<=n;i++)
	{
		notdelete=max(notdelete,(int)((num.end()-lower_bound(num.begin(),num.end(),i))*i));
	}
	ans=n-notdelete;
	cout<<ans<<endl;
	/*
	cout<<"notdelete="<<notdelete<<endl;
	*/
	#endif
}
int t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--) solve();
	return 0;
}
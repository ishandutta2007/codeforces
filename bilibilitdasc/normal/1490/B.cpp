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
int n,a[30000];
void solve()
{
	cin>>n;
	int valid=n/3,ans=0;
	int cnt[3]={0,0,0};
	rep(i,n)
	{
		cin>>a[i];
		cnt[a[i]%3]++;
	}
	if(cnt[1]>valid) {ans+=cnt[1]-valid;cnt[2]+=cnt[1]-valid;cnt[1]=valid;} 
	if(cnt[2]>valid) {ans+=cnt[2]-valid;cnt[0]+=cnt[2]-valid;cnt[2]=valid;} 
	if(cnt[0]>valid) {ans+=cnt[0]-valid;cnt[1]+=cnt[0]-valid;cnt[0]=valid;} 
	if(cnt[1]>valid) {ans+=cnt[1]-valid;cnt[2]+=cnt[1]-valid;cnt[1]=valid;} 
	if(cnt[2]>valid) {ans+=cnt[2]-valid;cnt[0]+=cnt[2]-valid;cnt[2]=valid;} 
	cout<<ans<<endl;
}
int t;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--) solve();
	return 0;
}
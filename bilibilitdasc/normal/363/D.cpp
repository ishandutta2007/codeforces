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
ll n,m,a,b[100005],p[100005],l,r,mid,ans;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	cin>>n>>m>>a;
	rep(i,n) cin>>b[i];
	rep(i,m) cin>>p[i];
	sort(b,b+n,cmp);
	sort(p,p+m);
	l=-1,r=min(n,m);//(l,r]
	while(r-l>1)
	{
		mid=(l+r)/2;
		ll al=0;
		rep(i,mid+1) al+=max(0ll,p[mid-i]-b[i]);
		if(al<=a)
		l=mid;
		else
		r=mid;
	}
	rep(i,l+1)
	{
		a-=max(0ll,p[l-i]-b[i]);
		ans+=min(b[i],p[l-i]);
	}
	ans=max(0ll,ans-a);
	cout<<l+1<<' '<<ans<<endl;
	return 0;
}
/*
not and or bitand bitor xor int long short signed unsigned float double using namespace typedef const constexpr true false if else
char struct static class this return auto union enum extern register void volatile switch for while do case goto default continue
break sizeof asm bool catch const_cast delete dynamic_cast explicit export friend inline mutable new operator private protected
reinterpret_cast static_cast template throw try typeid typename virtual wchar_t static_assert
*/
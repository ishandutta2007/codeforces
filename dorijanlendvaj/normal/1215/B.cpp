#include <bits/stdc++.h>

using namespace std;

int n,a,cnt1,cnt2,pref;
long long ans1,ans2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	++cnt1;
	for (int i=0;i<n;++i)
	{
		cin>>a;
		if (a<0) pref^=1;
		if (pref==1) ans1+=cnt2,ans2+=cnt1,++cnt2;
		else ans1+=cnt1,ans2+=cnt2,++cnt1;
	}
	cout<<ans2<<' '<<ans1;
}
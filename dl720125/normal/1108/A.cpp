#include <bits/stdc++.h>
//#define int long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if(l1!=r2) cout<<l1<<" "<<r2<<endl;
		else cout<<r1<<" "<<l2<<endl;
	}
	return 0;
}
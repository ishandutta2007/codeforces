#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		if(x==2) cout<<2<<endl;
		else if(x%2==0) cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
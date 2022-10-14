#include<bits/stdc++.h>
using namespace std;
long long tot=0;
int _main()
{
	tot=0;
	int n,m,q,t;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1; i<n; i++) scanf("%d",&t),tot+=t;
	if(tot+q>m) cout<<m; else cout<<tot+q;
	cout<<endl;
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--) _main();
}
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long int
#define endl '\n'


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	int mini=1e9;
	for(int i=0; i<m; i++){
		int l, r;
		cin>>l>>r;
		mini=min(mini, r-l+1);
	}
	cout<<mini<<endl;
	int ans[n];
	int val=0;
	for(int i=0; i<n;i++){
		ans[i]=val;
		val++;
		val=val%mini;
	}
	for(int i=0; i<n; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
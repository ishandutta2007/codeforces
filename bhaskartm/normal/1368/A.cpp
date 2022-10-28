#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int a ,b, n;
		cin>>a>>b>>n;
		if(a>n || b>n){
			cout<<0<<endl;
			continue;
		}
		int a1=max(a ,b);
		int a2=min(a, b);
		int cnt=0;
		while(a1<=n){
			a1=a1+a2;
			a2=a1-a2;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
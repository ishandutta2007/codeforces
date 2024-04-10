#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define endl '\n'
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int c2=0;
		int c3=0;
		while(n%2==0){
			n=n/2;
			c2++;
		}
		while(n%3==0){
			n=n/3;
			c3++;
		}
		if(n!=1 || c2>c3){
			cout<<-1<<endl;
			continue;
		}
		cout<<c3+(c3-c2)<<endl;
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		int val=abs(a-b);
		if(val%10==0){
			cout<<val/10<<endl;
		}
		else{
			cout<<(val/10)+1<<endl;
		}
	}
	return 0;
}
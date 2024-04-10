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
		int n;
		cin>>n;
		int c1=0;
		int c2=0;
		int sum=0;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			sum+=x;
			if(x==1){
				c1++;
			}
			else{
				c2++;
			}
		}
		
		if(sum%2==1){
			cout<<"NO"<<endl;
			continue;
		}
		sum=sum/2;
		bool che=0;
		for(int i=0; i<=c1; i++){
			if(i>sum){
				continue;
			}
			int rem=(sum-i);
			if(rem%2==1){
				continue;
			}
			if(rem/2<=c2){
				che=1;
			}
		}
		if(che){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
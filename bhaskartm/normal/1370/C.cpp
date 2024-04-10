#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'
int sv[1000005];
int pre[1000005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int val=n;
		int cnt=0;
		while(val%2==0){
			val=val/2;
			cnt++;
		}
		bool b=1;
		for(int x=2; x*x<=val; x++){
			if(val%x==0){
				b=0;
			}
		}
		if(n==1){
			cout<<"FastestFinger"<<endl;
			continue;
		}
		if(n==2){
			cout<<"Ashishgup"<<endl;
			continue;
		}
		if(cnt==0){
			cout<<"Ashishgup"<<endl;
			continue;
		}
		
		if(val==1){
			cout<<"FastestFinger"<<endl;
			continue;
		}
		if(cnt==1 && b==0){
			cout<<"Ashishgup"<<endl;
			continue;
		}
		if(cnt==1 && b==1){
			cout<<"FastestFinger"<<endl;
			continue;
		}
		if(cnt>1){
			cout<<"Ashishgup"<<endl;
			continue;
		}
	}
	return 0;
}
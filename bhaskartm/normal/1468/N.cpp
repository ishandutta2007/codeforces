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
		int c[3];
		for(int i=0; i<3; i++){
			cin>>c[i];
		}
		int a[5];
		for(int i=0; i<5; i++){
			cin>>a[i];
		}
		bool che=1;
		for(int i=0; i<3; i++){
			if(c[i]<a[i]){
				che=0;
			}
		}
		int r[3];
		for(int i=0; i<3; i++){
			r[i]=c[i]-a[i];
		}
		a[3]-=r[0];
		a[4]-=r[1];
		a[3]=max(a[3], 0LL);
		a[4]=max(a[4], 0LL);
		if(a[3]+a[4]>r[2]){
			che=0;
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
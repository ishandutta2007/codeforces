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
		int ans=0;
		bool che=1;
		for(int i=1; i<=9; i++){
			if(che==0){
				break;
			}
			int d=0;
			int num=0;
			while(1){
				num=num*10+i;
				
				d++;
				ans+=d;
				if(num==n){
					che=0;
					break;
				}
				if(d==4){
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
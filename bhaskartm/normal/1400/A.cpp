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
		string st;
		cin>>st;
		int cnt1=0;
		int cnt0=0;
		for(int i=0; i<st.size(); i++){
			if(st[i]=='0'){
				cnt0++;
			}
			else{
				cnt1++;
			}
		}
		if(cnt1>cnt0){
			for(int i=0; i<n; i++){
				cout<<'1';
			}
			cout<<endl;
		}
		else{
			for(int i=0; i<n; i++){
				cout<<'0';
			}
			cout<<endl;
		}
	}
	return 0;
}
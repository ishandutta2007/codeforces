#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define  pb push_back
#define  f first
#define  s second

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		bool o=0;
		bool z=0;
		for(int i=0; i<n; i++){
			if(s[i]=='1'){
				o=1;
			}
			if(s[i]=='0'){
				z=1;
			}
		}
		if(o==0 || z==0){
			cout<<s<<endl;
			continue;
		}
		int p1=-1;
		for(int i=0; i<n; i++){
			if(s[i]=='1'){
				p1=i;
				break;
			}
		}
		int p0=n+1;
		for(int i=n-1; i>=0; i--){
			if(s[i]=='0'){
				p0=i;
				break;
			}
		}
		if(p1>p0){
			cout<<s<<endl;
			continue;
		}
		string t;
		for(int i=0; i<p1; i++){
			t=t+s[i];
		}
		for(int i=p0; i<n; i++){
			t=t+s[i];
		}
		cout<<t<<endl;
	}
	return 0;
}
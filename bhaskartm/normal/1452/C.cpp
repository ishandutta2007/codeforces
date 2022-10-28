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
		string st;
		cin>>st;
		int ans=0;
		int c1=0;
		int c2=0;
		for(int i=0; i<st.size(); i++){
			if(st[i]=='('){
				c1++;
				continue;
			}
			if(st[i]=='['){
				c2++;
			}
			if(st[i]==')'){
				if(c1>0){
					c1--;
					ans++;
				}
			}
			if(st[i]==']'){
				if(c2>0){
					c2--;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
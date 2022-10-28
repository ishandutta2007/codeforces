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
		string ans;
		ans+="1";
		int curr=1+st[0]-'0';
		for(int i=1; i<st.size(); i++){
			if((st[i]-'0'+1)==curr){
				ans+="0";
				curr=st[i]-'0';
			}
			else{
				ans+="1";
				curr=(st[i]-'0'+1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
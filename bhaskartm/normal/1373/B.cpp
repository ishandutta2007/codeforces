#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'



main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int cnt1=0;
		int cnt2=0;
		for(int i=0; i<s.size(); i++){
			if(s[i]=='1'){
				cnt1++;
			}
			else{
				cnt2++;
			}
		}
		int val=min(cnt1, cnt2);
		if(val%2==0){
			cout<<"NET"<<endl;
		}
		else{
			cout<<"DA"<<endl;
		}
	}
	return 0;
}
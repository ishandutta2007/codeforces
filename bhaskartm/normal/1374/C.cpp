#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define endl '\n'
#define pb push_back

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
		int mini=0;
		int num=0;
		for(int i=0; i<s.size(); i++){
			if(s[i]=='('){
				num++;
				mini=min(mini, num);
			}
			else{
				num--;
				mini=min(mini, num);
			}
		}
		cout<<(-mini)<<endl;
	}
	
	return 0;
}
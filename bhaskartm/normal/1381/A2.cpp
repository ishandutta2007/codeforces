#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int

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
		string a, b;
		cin>>a>>b;
		vector<int>ans;
		

		int num=0;
		int fir, las;
		for(int i=n-1; i>=0; i--){
			if(num%2==0){
				fir=a[(num/2)]-'0';
				las=a[n-1-(num/2)]-'0';
			}
			else{
				fir=1-(a[n-1-(num/2)]-'0');
				las=1-(a[(num+1)/2]-'0');
			}
			num++;
			if((b[i]-'0')==fir){
				ans.pb(1);
				ans.pb(i+1);
			}
			else{
				ans.pb(i+1);
			}
		}
		cout<<ans.size()<<" ";
		for(auto u:ans){
			cout<<u<<" ";
		}
		cout<<endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
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
		int n, k;
		cin>>n>>k;
		int arr[n];
		bool b=0;
		int val=0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			if(arr[i]%k!=0){
				b=1;
			}
			arr[i]=arr[i]%k;
			val+=arr[i];
		}
		if(b==0){
			cout<<-1<<endl;
			continue;
		}
		if(val%k!=0){
			cout<<n<<endl;
			continue;
		}
		vector<int>fr;
		vector<int>ba;
		for(int i=0; i<n; i++){
			fr.pb(arr[i]);
		}
		while(fr.back()==0){
			fr.pop_back();
		}
		for(int i=n-1; i>=0; i--){
			ba.pb(arr[i]);
		}
		while(ba.back()==0){
			ba.pop_back();
		}
		cout<<max(fr.size()-1, ba.size()-1)<<endl;
	}
	return 0;
}
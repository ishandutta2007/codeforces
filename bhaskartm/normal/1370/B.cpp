#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define int long long int
#define endl '\n'
int sv[1000005];
int pre[1000005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>o;
		vector<int>e;
		for(int i=1; i<=2*n; i++){
			int x;
			cin>>x;
			if(x%2==0){
				e.pb(i);
			}
			else{
				o.pb(i);
			}
		}
		if(o.size()%2==1){
			o.pop_back();
			e.pop_back();
		}
		else{
			if(o.size()>0){
				o.pop_back();
				o.pop_back();
			}
			else{
				e.pop_back();
				e.pop_back();
			}
		}
		for(int i=0; i<e.size(); i=i+2){
			cout<<e[i]<<" "<<e[i+1]<<endl;
		}
		for(int i=0; i<o.size(); i=i+2){
			cout<<o[i]<<" "<<o[i+1]<<endl;
		}
	}
	return 0;
}
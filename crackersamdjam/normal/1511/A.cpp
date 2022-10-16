#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;



int main(){
	int t, n, r;
	cin>>t;
	while(t--){
		cin>>n;
		int ans = 0;
		while(n--){
			cin>>r;
			if(r != 2){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
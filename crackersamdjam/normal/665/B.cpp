#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int n, m, k, ans;

int main(){
	cin>>n>>m>>k;
	vector<int> v(k);
	for(int i = 0; i < k; i++){
		cin>>v[i];
	}
	while(n--){
		for(int t = 0; t < m; t++){
			int a; cin>>a;
			for(int i = 0; i < k; i++){
				if(v[i] == a){
					ans += i+1;
					v.erase(v.begin()+i);
					v.insert(v.begin(), a);
					break;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n, k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		vector<int> out;
		for(int i = k-1; i > 0 and i+i+1 > k; i--){
			out.emplace_back(i);
		}
		for(int i = k+1; i <= n; i++)
			out.emplace_back(i);
		cout<<size(out)<<'\n';
		for(int i: out)
			cout<<i<<' ';
		cout<<'\n';
	}
}
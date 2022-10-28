#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define int long long int
vector<vector<int>>v;
 
 
 
main() {
	int n;
	cin>>n;
	v.resize(1000001);
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		v[x].push_back(i);
	}
	int ans=0;
	int den=n*n;
	for(int i=1; i<=1000000; i++){
		if(v[i].size()==0){
			continue;
		}
		
		int last=-1;
		for(int j=0; j<v[i].size(); j++){
			ans+=((v[i][j]-(last))*(n-v[i][j]))*2-1;
			
			last=v[i][j];
		}
	}
	cout<<setprecision(20)<<((1.0)*(ans))/den;
	return 0;
}
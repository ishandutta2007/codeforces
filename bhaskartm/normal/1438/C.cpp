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
		int n, m;
		cin>>n>>m;
		int a[n][m];
		map<int, vector<pair<int, int>>>ma;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>a[i][j];
				ma[a[i][j]].pb({i, j});
			}
		}
		int b[n][m];
		int iter=0;
		for(auto it=ma.begin(); it!=ma.end(); it++){
			iter=iter+1;
			iter=iter%2;
			for(auto u:it->second){
				if((u.f+u.s)%2==iter){
					b[u.f][u.s]=a[u.f][u.s]+1;
				}
				else{
					b[u.f][u.s]=a[u.f][u.s];
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout<<b[i][j]<<" ";
				
			}
			cout<<endl;
		}
		
	}
	return 0;
}
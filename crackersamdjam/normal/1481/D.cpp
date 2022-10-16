#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1005, NN = 1e5+5;

int t, n, m;
string adj[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 1; i <= n; i++){
			cin>>adj[i];
			adj[i] = " "+adj[i];
		}
		if(m%2 or (adj[1][2] == adj[2][1])){
			cout<<"YES\n";
			for(int i = 0; i < m+1; i++)
				cout<<(i%2+1)<<' ';
			cout<<'\n';
		}
		else if(n > 2){
			array<int, 3> v = {1, 2, 3};
			do{
				auto [a, b, c] = v;
				if(adj[a][b] == adj[b][c]){
					cout<<"YES\n";
					int i = ((1-m/2)%3+3)%3;
					m++;
					while(m--){
						cout<<v[i]<<' ';
						i = (i+1)%3;
					}
					cout<<'\n';
					break;
				}
			} while(next_permutation(all(v)));
		}
		else
			cout<<"NO\n";
	}
}
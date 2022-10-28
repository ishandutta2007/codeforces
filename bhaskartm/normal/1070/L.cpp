#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
vector<vector<int>>adj;

const int N=2005;

vector<bitset<N>>b;

int gauss (vector<bitset<N>> a, int n, int m, vector<int>& ans){  
    vector<int> where (m, -1);                                      
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
            	a[i]=a[i]^a[row];
            	
           
        ++row;
    }
    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    return 1;
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		adj.clear();
		cin>>n>>m;
		adj.resize(n+1);
		b.clear();
		b.resize(n+1);
		int deg[n+1];
		for(int i=0; i<=n; i++){
			deg[i]=0;
		}
		for(int i=0; i<m; i++){
			int u, v;
			cin>>u>>v;
			u--;
			v--;
			adj[u].pb(v);
			adj[v].pb(u);
			deg[u]++;
			deg[v]++;
		}
		bool che=1;
		for(int i=0; i<n; i++){
			if(deg[i]%2==1){
				che=0;
			}
		}
		if(che){
			cout<<1<<endl;
			for(int i=1; i<=n; i++){
				cout<<1<<" ";
			}
			cout<<endl;
			continue;
		}
		for(int i=0; i<n; i++){
			if(deg[i]%2==0){
				for(auto u:adj[i]){
					b[i].set(u);
				}
				
			}
			else{
				for(auto u:adj[i]){
					b[i].set(u);
				}
				b[i].set(i);
				b[i].set(n);
			}
		}
		vector<int>ans;
		int val=gauss(b, n, n, ans);
		cout<<2<<endl;
		for(auto u:ans){
			cout<<u+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}
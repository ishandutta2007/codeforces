#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'

vector<int>vx;
vector<int>vy;
int n;

bool che(int i, int j){
	return (i>=0 && j>=0 && i<n && j<n);
}
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	vx.pb(-1);
	vx.pb(0);
	vx.pb(1);
	vy.pb(-1);
	vy.pb(0);
	vy.pb(1);
	while(t--){
		
		cin>>n;
		int arr[n][n];
		bool don[n][n];
		int ans[n][n];
		vector<vector<vector<pair<int, int>>>>ne;
		
		ne.resize(n);
		
		for(int i=0; i<n; i++){
			ne[i].resize(n);
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>arr[i][j];
				don[i][j]=0;
				ans[i][j]=0;
			}
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(auto u1:vx){
					for(auto u2:vy){
						int val=abs(u1)+abs(u2);
						if(val==1){
							if(che(i+u1, j+u2)){
								ne[i][j].pb({i+u1, j+u2});
							}
						}
					}
				}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				for(auto u:ne[i][j]){
					int ux=u.f;
					int uy=u.s;
					int cn=0;
					for(auto u2:ne[ux][uy]){
						if(!don[u2.f][u2.s]){
							cn++;
						}
					}
					if(cn==1){
						ans[i][j]=arr[ux][uy];
						for(auto u:ne[ux][uy]){
							if(u.f==i && u.s==j){
								continue;
							}
							ans[i][j]=ans[i][j]^ans[u.f][u.s];
						}
						don[i][j]=1;
						break;
					}
				}
				don[i][j]=1;
			}
		}
		int ret=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				ret=ret^ans[i][j];
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}
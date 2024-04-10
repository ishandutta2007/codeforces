#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	int f[m+1];
	vector<vector<int>>v;
	v.resize(m+1);
	int sz[m+1];
	for(int i=0; i<=m; i++){
		sz[i]=0;
	}
	int val[n+1];
	for(int i=1; i<=n; i++){
		int x;
		cin>>x;
		sz[x]++;
		val[i]=x;
		v[x].pb(i);
	}
	for(int i=0; i<=m; i++){
		f[i]=i;
	}
	int num=0;
	for(int i=1; i<n; i++){
		if(val[i]==val[i+1]){
			num++;
		}
	}
	cout<<n-1-num<<endl;
	for(int i=0; i<m-1; i++){
		int a, b;
		cin>>a>>b;
		int aa=f[a];
		int bb=f[b];
		if(v[aa].size()>v[bb].size()){
			for(auto u:v[bb]){
				if(u==n){
					if(val[u-1]==aa){
						num++;
						
					}
					continue;
				}
				if(u==1){
					if(val[2]==aa){
						num++;
						
					}
					
					continue;
				}
				if(val[u+1]==aa){
					num++;
				}
				if(val[u-1]==aa){
					num++;
				}
			}
			for(auto u:v[bb]){
				val[u]=aa;
				v[aa].pb(u);
			}
			f[a]=aa;
			f[b]=aa;
		}
		else{
			for(auto u:v[aa]){
				if(u==n){
					if(val[u-1]==bb){
						num++;
						
					}
					continue;
				}
				if(u==1){
					if(val[2]==bb){
						num++;
						
					}
					continue;
				}
				if(val[u+1]==bb){
					num++;
				}
				if(val[u-1]==bb){
					num++;
				}
			}
			for(auto u:v[aa]){
				val[u]=bb;
				v[bb].pb(u);
			}
			f[a]=bb;
			f[b]=bb;
		}
		cout<<n-1-num<<endl;
	}
	
	return 0;
}
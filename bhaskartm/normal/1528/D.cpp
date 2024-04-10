#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=605;

vector<vector<pair<int, int>>>adj;
vector<vector<pair<int, int>>>a;
vector<vector<pair<int, int>>>b;
int d[N];
bool pre[N];

 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	adj.resize(n);
	a.resize(n);
	b.resize(n);
	for(int i=0; i<m; i++){
		int aa, bb, cc;
		cin>>aa>>bb>>cc;
		adj[aa].pb({bb, cc});
	}
	
	for(int i=0; i<n; i++){
		sort(adj[i].begin(), adj[i].end());
	}
	
	for(int i=0; i<n; i++){
		a[i].pb(adj[i][0]);
		int sz=adj[i].size();
		for(int j=1; j<sz; j++){
			if(adj[i][j].s-adj[i][j].f <= -a[i].back().f+a[i].back().s){
				a[i].pb(adj[i][j]);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(auto u:a[i]){
			if(u.s-u.f<=(-a[i].back().f)+a[i].back().s+n){
				b[i].pb(u);
			}
		}
	}
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			d[j]=2e9;
			pre[j]=0;
		}
		d[i]=0;
		for(int rep=0; rep<n; rep++){
			int mini=2e9;
			int ind=-1;
			for(int j=0; j<n; j++){
				if(pre[j]==0 && d[j]<mini){
					mini=d[j];
					ind=j;
				}
			}
			
			pre[ind]=1;
			int sz=b[ind].size();
			int tim=(d[ind]%n);
			for(int j=0; j<sz; j++){
				int n1=(b[ind][j].f+tim)%n;
				int n2=(b[ind][(j+1)%sz].f+tim)%n;
				int cnt=0;
				d[n1]=min(d[n1], d[ind]+cnt+b[ind][j].s);
				cnt++;
				n1=(n1+1)%n;
				while(n1!=n2){
					d[n1]=min(d[n1], d[ind]+cnt+b[ind][j].s);
					cnt++;
					n1=(n1+1)%n;
				}
			}
		}
		for(int j=0; j<n; j++){
			cout<<d[j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
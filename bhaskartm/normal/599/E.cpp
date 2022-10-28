#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=13;


int n, m, q;
bool ed[N][N];
int lc[N][N];
long long int dp[(1<<N)][N];
map<pair<int, int>, set<int>>ma;

 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>q;
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		u--;
		v--;
		ed[u][v]=1;
		ed[v][u]=1;
		
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			lc[i][j]=-1;
		}
	}
	for(int i=0; i<q; i++){
		int a, b, c;
		cin>>a>>b>>c;
		a--;
		b--;
		c--;
		if(a==b && a!=c){
			cout<<0<<endl;
			return 0;
		}
		lc[a][b]=c;
		lc[b][a]=c;
		ma[{a, b}].insert(c);
		ma[{b, a}].insert(c);
	}
	for(auto u:ma){
		set<int>y=u.second;
		int sz=y.size();
		if(sz>1){
			cout<<0<<endl;
			return 0;
		}
	}
	
	for(int i=0; i<n; i++){
		dp[(1<<i)][i]=1;
	}

	for(int j=1; j<(1<<n); j++){
		for(int i=0; i<n; i++){
			if((__builtin_popcount(j)==1) || (((1<<i)&j)==0)){
				continue;
			}
			int ms=(j-(1<<i));
			int ind=-1;
			for(int k=0; k<n; k++){
				if((ms&(1<<k))){
					ind=k;
				}
			}
			int ms2=ms-(1<<ind);
			for (int sub=ms2; ; sub=(sub-1)&ms2) {
				int bmask=(ms2^sub);
				bmask+=(1<<i);
				int smask=(sub+(1<<ind));
				
				vector<int>v1;
				vector<int>v2;
				for(int i=0; i<n; i++){
					if(((1<<i)&bmask)){
						v1.pb(i);
					}
				}
				for(int i=0; i<n; i++){
					if(((1<<i)&smask)){
						v2.pb(i);
					}
				}
				
				vector<int>vec;
				for(auto u:v2){
					if(ed[u][i]){
						vec.pb(u);
					}
				}
				int sz=vec.size();
				if(sz>1){
					continue;
				}
				
				bool che=1;
				for(auto u1:v1){
					for(auto u2:v2){
						if(lc[u1][u2]==-1 || lc[u1][u2]==i){
							continue;
						}
						che=0;
					}
				}
				for(auto u1:v1){
					for(auto u2:v2){
						if(ed[u1][u2] && u1!=i){
							che=0;
						}
					}
				}
				
				if(che){
					if(sz==1){
						dp[j][i]+=(dp[smask][vec[0]]*dp[j^smask][i]);
					}
					else{
						for(auto u:v2){
							dp[j][i]+=(dp[smask][u]*dp[j^smask][i]);
						}
					}
				}
				
				if (sub==0)  break;
			}
		}
	}
	
	cout<<dp[(1<<n)-1][0]<<endl;
	
	return 0;
}
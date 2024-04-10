#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll N,M;
vector<vector<bool> > v;
vector<vector<bool> > vis;
vector<vector<ll> > memo;
ll sol(ll x,ll y){
	if(x==M-1 && y==N-1)return memo[x][y]=1;
	if(vis[x][y])return memo[x][y];
	vis[x][y]=1;
	if(x<M-1 && v[x+1][y])memo[x][y]=max(memo[x][y],sol(x+1,y));
	if(y<N-1 && v[x][y+1])memo[x][y]=max(memo[x][y],sol(x,y+1));
	return memo[x][y];
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		cin>>N>>M;
		for(ll i=0;i<=M;i++){
			v.push_back(vector<bool>(N+1,0));
			vis.push_back(vector<bool>(N+1,0));
			memo.push_back(vector<ll>(N+1,0));
		}
		for(ll i=0;i<N;i++){
			string a;
			cin>>a;
			for(ll j=0;j<M;j++){
				if(a[j]=='.')v[j][i]=1;
			}
		}
		sol(0,0);
		if(memo[0][0]==0){
			cout<<0;
			return 0;
		}
		vector<pair<int,int> > p1,p2;
		int x=0,y=0;
		while(x!=M-1 || y!=N-1){
			if(x<M-1 && memo[x+1][y])x++;
			else y++;
			p1.push_back({x,y});
		}
		x=0,y=0;
		while(x!=M-1 || y!=N-1){
			if(y<N-1 && memo[x][y+1])y++;
			else x++;
			p2.push_back({x,y});
		}
		for(int i=0;i<p2.size()-1;i++){
			if(p1[i]==p2[i]){
				cout<<1;
				return 0;
			}
		}
		cout<<2;
		return 0;
}
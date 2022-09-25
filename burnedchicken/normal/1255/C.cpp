#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=100005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	int q[n-2][3];
	loop(n-2) cin >> q[i][0] >> q[i][1] >> q[i][2];
	vector<int> adj[n+1];
	int cnt[n+1];
	vector<int> ans;
	bool inans[n+1];
	loop(n+1) inans[i]=false;
	loop(n-2){
		adj[q[i][0]].push_back(q[i][1]);
		adj[q[i][0]].push_back(q[i][2]);
		adj[q[i][1]].push_back(q[i][0]);
		adj[q[i][1]].push_back(q[i][2]);
		adj[q[i][2]].push_back(q[i][0]);
		adj[q[i][2]].push_back(q[i][1]);
	}
	int x;
	loop(n+1){
		if(i==0) continue;
		if(adj[i].size()==2){
			x=i;
			ans.push_back(i);
			inans[i]=true;
			if(adj[adj[i][0]].size()==4){
				x=adj[i][0];
				ans.push_back(x);
				inans[x]=true;
			}
			else if(adj[adj[i][1]].size()==4){
				x=adj[i][1];
				ans.push_back(x);
				inans[x]=true;
			}
			break;
		}
	}
	int y[2];
	loop(n-2){
		y[0]=y[1]=-1;
		loopi(j,adj[x].size()){
			if(inans[adj[x][j]]) continue;
			if(adj[x][j]==y[0]||adj[x][j]==y[1]){
				x=adj[x][j];
				ans.push_back(x);
				inans[x]=true;
				break;
			}
			if(y[0]==-1) y[0]=adj[x][j];
			else y[1]=adj[x][j];
		}
	}
	loop(n+1){
		if(i==0) continue;
		if(!inans[i]) ans.push_back(i);
	}
	loop(ans.size()){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}
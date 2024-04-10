#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=200005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,m,ans;
	cin >> n >> m;
	int e1,e2;
	vector<int> adj[maxn];
	loop(m){
		cin >> e1 >> e2;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	int pre[n+1];
	loop(n+1) pre[i]=i;
	list<int> lis;
	bool visited[n+1];
	loop(n+1) visited[i]=false;
	vector<int> vec;
	loop(n+1){
		if(i==0) continue;
		if(visited[i]) continue;
		lis.push_back(i);
		visited[i]=true;
		vec.push_back(i);
		//cout << i << "\n";
		while(!lis.empty()){
			pre[lis.front()]=i;
			loopi(j,adj[lis.front()].size()){
				if(!visited[adj[lis.front()][j]]){
					lis.push_back(adj[lis.front()][j]);
					visited[adj[lis.front()][j]]=true;
				}
			}
			lis.pop_front();
		}
	}
	int Max[n+1];
	loop(n+1) Max[i]=-1;
	loop(n+1){
		if(i==0) continue;
		Max[pre[i]]=i;
	}
	ans=0;
	int x=-1;
	int y=0;
	loop(vec.size()){
	    y=max(y,Max[vec[i]]);
	    x=max(i+1,x);
		while(1){
		    if(x>=vec.size()) break;
		    if(y>vec[x]){
		        x++;
		        ans++;
		    }
		    else break;
		}
	}
	cout << ans << "\n";
	return 0;
}
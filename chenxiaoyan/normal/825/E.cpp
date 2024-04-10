/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100000,M=100000;
int n,m;
vector<int> nei[N+1];
int ideg[N+1];
vector<int> topo;
int ans[N+1];
void toposort(){
	priority_queue<int> q;
	for(int i=1;i<=n;i++)if(!ideg[i])q.push(i);
	while(q.size()){
		int x=q.top();
		q.pop();
		topo.pb(x);
		for(int i=0;i<nei[x].size();i++){
			int y=nei[x][i];
			if(!--ideg[y])q.push(y);
		}
	}
}
int main(){
	cin>>n>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		nei[y].pb(x);
		ideg[x]++;
	}
	toposort();
	reverse(topo.begin(),topo.end());
	for(int i=0;i<n;i++)ans[topo[i]]=i+1;
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<pair<int,int> > edge;
vector<int> v[6000];
bool vis[6000];
bool detectciclo(int a,int b){
	fill(vis,vis+5500,0);
	queue<int> q;
	q.push(b);
	while(!q.empty()){
		int pos=q.front();
		q.pop();
		if(vis[pos])continue;
		vis[pos]=1;
		if(pos==a)return 1;
		for(int i=0;i<v[pos].size();i++)q.push(v[pos][i]);
	}
	return 0;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		int N,M;
		cin>>N>>M;
		for(int i=0;i<M;i++){
			int a,b;
			cin>>a>>b;
			edge.push_back({a,b});
			v[a].push_back(b);
		}
		bool ciclo=0;
		for(int i=0;i<M;i++){
			if(detectciclo(edge[i].first,edge[i].second)){
				ciclo=1;
				break;
			}
		}
		if(ciclo==0){
			cout<<1<<endl;
			for(int i=0;i<M;i++)cout<<1<<" ";
			return 0;
		}
		fill(vis,vis+5500,0);
		cout<<2<<endl;
		for(int i=0;i<M;i++){
			cout<<(edge[i].first>edge[i].second)+1<<" ";
		}
		return 0;
}
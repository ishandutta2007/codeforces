#include<bits/stdc++.h>
const int N=2000050;
using namespace std;

priority_queue<pair<int,int>> q;
struct num{int x;num(){cin>>x;}operator int(){return x;}};
#define fore(k) for(auto _to:e[k])
vector<int> e[N];int in[N];
void add(int fr,int to){
    e[fr].push_back(to);
	in[to]++;
}

int v[N],p[N];
vector<pair<int,int>> ans;
bool cmd(int x,int y){return p[x]>p[y];}

int main(){
	num n,m;
	for(int i=1;i<=m;i++){
		num x,y;
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++){
		p[i]=in[i]/2;
		q.push({-p[i],i});
	}
	while(!q.empty()){
		int nw=q.top().second;q.pop();
		if(v[nw])continue;
		v[nw]=1;
		sort(e[nw].begin(),e[nw].end(),cmd);
		fore(nw){
			if(!p[nw]) {
				if(!v[_to])
					ans.push_back({nw,_to});
			}
			else p[_to]--,p[nw]--,q.push({-p[_to],_to});
		}
	}
	cout<<ans.size()<<endl;
	for(auto x:ans)cout<<x.first<<' '<<x.second<<'\n';
	cout<<endl;
}
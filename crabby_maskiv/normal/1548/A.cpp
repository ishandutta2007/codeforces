#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
set<int> st[N];
bool ans[N];
int answ;
inline bool check(int x){
	int t;
	if(st[x].size()==0) t=1;
	else{
		int f=(*st[x].rbegin());
		if(f<x) t=1;
		else t=0;
	}
	answ-=ans[x];
	ans[x]=t;
	answ+=t;
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		st[u].insert(v);
		st[v].insert(u);
	}
	for(i=1;i<=n;i++) check(i);
	int q;cin>>q;
	while(q--){
		int op,x,y;cin>>op;
		if(op==1){
			cin>>x>>y;
			st[x].insert(y);
			st[y].insert(x);
			check(x);check(y);
		}
		else if(op==2){
			cin>>x>>y;
			st[x].erase(y);
			st[y].erase(x);
			check(x);check(y);
		}
		else cout<<answ<<endl;
	}
	return 0;
}
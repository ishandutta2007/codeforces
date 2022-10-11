#include<bits/stdc++.h>
using namespace std;
int a,b;bool OK=false;
void bfs(long long p,vector<int>G){
	G.push_back(p);
	if(p>b || OK==true)return;
	if(p==b){
		OK=true;cout<<"YES"<<endl;
		cout<<G.size()<<endl;
		for(int i=0;i<(int)G.size();i++){if(i)cout<<' ';cout<<G[i];}cout<<endl;
		return;
	}
	bfs(p*2,G);
	bfs(p*10+1,G);
}
int main(){
	cin>>a>>b;bfs(a,vector<int>{});
	if(OK==false){cout<<"NO"<<endl;}
	return 0;
}
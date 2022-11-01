#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
template<class T>
bool uin(T &a,T b){
	if(a>b){
		a=b;
		return true;
	}
	return false;
}
template<class T>
bool uax(T &a,T b){
	if(a<b){
		a=b;
		return true;
	}
	return false;
}
vector<int> e[30],ord;
int vis[30];

bool dfs(int v){
	if(vis[v]==2) return true;
	if(vis[v]==1) return false;
	vis[v]=1;
	for(int i=0;i<e[v].size();i++){
		if(!dfs(e[v][i])) return false;
	} 
	vis[v]=2;
	ord.push_back(v);
	return true;
}
int main(){
	int n;
	cin>>n;
	vector<string> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bool ok=1;
	for(int i=0;i<n-1;i++){
		int j=0;
		while(j<a[i].size() && j<a[i+1].size() && a[i+1][j]==a[i][j]) ++j;
		if(j==a[i+1].size() && j<a[i].size()) ok=0;
		else if(j<a[i].size() && j<a[i+1].size()){
			e[a[i][j]-'a'].push_back(a[i+1][j]-'a');
		}
	}
	for(int i=0;i<26;i++) ok&=dfs(i);
	if(!ok) cout<<"Impossible";
	else{
		reverse(ord.begin(),ord.end());
		for(int i=0;i<26;i++){
			cout<<((char)('a'+ord[i]));
		}
	}
	return 0;
}
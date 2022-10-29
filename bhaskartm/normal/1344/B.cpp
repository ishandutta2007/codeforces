#include <bits/stdc++.h>
using namespace std;
int cnt;
bool vis[1002][1002];
char arr[1002][1002];
int n, m;
void dfs(int i, int j){
	vis[i][j]=true;
	if(i+1<n && arr[i+1][j]=='#' && vis[i+1][j]==false){
		
		dfs(i+1, j);
		
	}
	if(i-1>=0 && arr[i-1][j]=='#' && vis[i-1][j]==false){
		dfs(i-1, j);
	}
	if(j+1<m && arr[i][j+1]=='#' && vis[i][j+1]==false){
		dfs(i, j+1);
	}
	if(j-1>=0 && arr[i][j-1]=='#' && vis[i][j-1]==false){
		dfs(i, j-1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}
	bool b1=false;
	bool b2=false;
	for(int i=0; i<n; i++){
		bool booly=true;
		for(int j=0; j<m; j++){
			if(arr[i][j]=='#'){
				booly=false;
			}
		}
		if(booly==true){
			b1=true;
			break;
		}
	}
	for(int j=0; j<m; j++){
		bool booly=true;
		for(int i=0; i<n; i++){
			if(arr[i][j]=='#'){
				booly=false;
			}
		}
		if(booly==true){
			b2=true;
			break;
		}
	}
	if((b1 && (!b2)) || ((!b1) && b2)){
		cout<<-1;
		return 0;
	}
	
	for(int i=0; i<n; i++){
		
		vector<int>v;
		for(int j=0; j<m; j++){
			if(arr[i][j]=='#'){
				if(v.size()==0){
					v.push_back(1);
				}
				else if(v[v.size()-1]==0){
					v.push_back(1);
				}
				else{
					
				}	
				
			}
			if(arr[i][j]=='.'){
				if(v.size()==0){
					v.push_back(0);
				}
				else if(v[v.size()-1]==1){
					v.push_back(0);
				}
				else{
					
				}
			}
		}
		
		if(v.size()>3 || ((v.size()==3) && (v[0]==1))){
			cout<<-1;
			return 0;
		}
	}
	for(int j=0; j<m; j++){
		
		vector<int>v;
		for(int i=0; i<n; i++){
			if(arr[i][j]=='#'){
				if(v.size()==0){
					v.push_back(1);
				}
				else if(v[v.size()-1]==0){
					v.push_back(1);
				}
				else{
					
				}	
				
			}
			if(arr[i][j]=='.'){
				if(v.size()==0){
					v.push_back(0);
				}
				else if(v[v.size()-1]==1){
					v.push_back(0);
				}
				else{
					
				}
			}
		}
		if(v.size()>3 || ((v.size()==3) && (v[0]==1))){
			cout<<-1;
			return 0;
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j]=='#' && (!vis[i][j])){
				
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
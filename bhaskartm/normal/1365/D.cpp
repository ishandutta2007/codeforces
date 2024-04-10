#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back
char arr[50][50];
int vis[50][50];
int cnt=0;
int n, m;
 
void dfs(int i, int j){
	vis[i][j]=1;
	if(i+1<n && arr[i+1][j]=='.' && vis[i+1][j]==0){
		dfs(i+1, j);
	}
	if(i+1<n && arr[i+1][j]=='G' && vis[i+1][j]==0){
		cnt++;
		dfs(i+1, j);
	}
	if(i-1>=0 && arr[i-1][j]=='.' && vis[i-1][j]==0){
		dfs(i-1, j);
	}
	if(i-1>=0 && arr[i-1][j]=='G' && vis[i-1][j]==0){
		cnt++;
		dfs(i-1, j);
	}
	if(j+1<m && arr[i][j+1]=='.' && vis[i][j+1]==0){
		dfs(i, j+1);
	}
	if(j+1<m && arr[i][j+1]=='G' && vis[i][j+1]==0){
		cnt++;
		dfs(i, j+1);
	}
	if(j-1>=0 && arr[i][j-1]=='.' && vis[i][j-1]==0){
		dfs(i, j-1);
	}
	if(j-1>=0 && arr[i][j-1]=='G' && vis[i][j-1]==0){
		cnt++;
		dfs(i, j-1);
	}
}
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		
		cin>>n>>m;
		int num=0;
		bool b=true;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>arr[i][j];
				if(arr[i][j]=='G'){
				num++;
				b=false;
			}
			}
			
		}
		if(b==true){
			cout<<"Yes"<<endl;
			continue;
		}
		bool che=true;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j]=='B'){
					if(i+1<n && arr[i+1][j]=='.'){
						arr[i+1][j]='#';
					}
					if(i+1<n && arr[i+1][j]=='G'){
						che=false;
					}
					if(i-1>=0 && arr[i-1][j]=='.'){
						arr[i-1][j]='#';
					}
					if(i-1>=0 && arr[i-1][j]=='G'){
						che=false;
					}
					if(j+1<m && arr[i][j+1]=='.'){
						arr[i][j+1]='#';
					}
					if(j+1<m && arr[i][j+1]=='G'){
						che=false;
					}
					if(j-1>=0 && arr[i][j-1]=='.'){
						arr[i][j-1]='#';
					}
					if(j-1>=0 && arr[i][j-1]=='G'){
						che=false;
					}
				}
			}
		}
		
		if(che==false){
			cout<<"No"<<endl;
			
			continue;
		}
		if(arr[n-1][m-1]=='#'){
			cout<<"No"<<endl;
			continue;
		}
		
		dfs(n-1, m-1);
	
		if(cnt==num){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){
				vis[i][j]=0;
			}
		}
		cnt=0;
	}
}
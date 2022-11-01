#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
int n,m,cx[4]={-1,0,1,0},cy[4]={0,1,0,-1};
char c[55][55];
void dfs(int i,int j,int n,char h){
	for(int k=0;k<4;k++){
		if(c[i+cx[k]][j+cy[k]]=='$' && n>=4){
			cout<<"Yes"<<endl;
			exit(0);
		}
		if(c[i+cx[k]][j+cy[k]]==h && i+cx[k]>=1 && i+cx[k]<=n && j+cy[k]>=1 && j+cy[k]<=m){
			char hh=c[i+cx[k]][j+cy[k]];
			c[i+cx[k]][j+cy[k]]=c[i+cx[k]][j+cy[k]]+('a'-'A');
			dfs(i+cx[k],j+cy[k],n+1,h);
			c[i+cx[k]][j+cy[k]]=hh;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(c[i][j]==c[i+1][j] && c[i+1][j]==c[i][j+1] && c[i][j+1]==c[i+1][j+1]){
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]>='A' && c[i][j]<='Z'){
				char ch;
				ch=c[i][j];
				c[i][j]='$';
				dfs(i,j,1,ch);
				c[i][j]=ch;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
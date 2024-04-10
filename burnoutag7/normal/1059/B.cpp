/******************
*  Writer: BD747  *
******************/
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

int n,m;
char g[1005][1005];
bool a[1005][1005];

bool chk(int i,int j){
	if(g[i-2][j-2]=='#'
	 &&g[i-2][j-1]=='#'
	 &&g[i-2][j]=='#'
	 
	 &&g[i-1][j-2]=='#'
	 &&g[i-1][j]=='#'
	 
	 &&g[i][j-2]=='#'
	 &&g[i][j-1]=='#'
	 &&g[i][j]=='#'){
	 	return true;
	 }else{
	 	return false;
	 }
}

void pnt(int i,int j){
	a[i-2][j-2]=1;
	a[i-2][j-1]=1;
	a[i-2][j]=1;
	
	a[i-1][j-2]=1;
	a[i-1][j]=1;
	
	a[i][j-2]=1;
	a[i][j-1]=1;
	a[i][j]=1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}
	
	for(int i=3;i<=n;i++){
		for(int j=3;j<=m;j++){
			if(chk(i,j)){
				pnt(i,j);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]=='#'&&a[i][j]!=1){
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}
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
int n,a[305],r,b;
char s[305][305];
bool u[305],v[305][305];
void dfs(int x){
	v[b][x]=1;
	if(!u[a[x]]){
		r=min(r,a[x]);
	}
	for(int j=0;j<n;j++){
		if(s[x][j]=='1' && !v[b][j]){
			dfs(j);
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(b=0;b<n;b++){
		r=n;
		dfs(b);
		u[r]=1;
		cout<<r<<' ';
	}
	return 0;
}
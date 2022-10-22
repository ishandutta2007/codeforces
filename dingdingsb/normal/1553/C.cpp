// Problem: Penalty
// Contest: Codeforces
// URL: https://m1.codeforces.ml/contest/1553/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;char str[10];
int col[10];int suf[11][2];
int mn;
void dfs(int now){
	if(now==10){
		int a=0,b=0;
		for(int i=0;i<10;i++){
			if(i&1)a+=col[i];else b+=col[i];
			if(a>b+suf[i+1][0])mn=min(mn,i+1);
			if(b>a+suf[i+1][1])mn=min(mn,i+1);
		}return;
	}
	if(str[now]=='0')col[now]=0,dfs(now+1);
	else if(str[now]=='1')col[now]=1,dfs(now+1);
	else col[now]=0,dfs(now+1),col[now]=1,dfs(now+1);
}
signed main(){
	for(int i=9;~i;i--){
		suf[i][0]=suf[i+1][0];
		suf[i][1]=suf[i+1][1];
		suf[i][i&1]++;
	}
	cin>>t;
	while(t--){
		cin>>str;mn=10;
		dfs(0);cout<<mn<<endl;
	}
	return 0;
	cout<<"cfnm*l";
}
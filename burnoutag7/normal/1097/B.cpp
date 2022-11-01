/******************
*  Author: BD747  *
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
#include<bits/stdc++.h>
using namespace std;

int n;
int a[20];

bool dfs(int dp,int cur){
	if(dp==n){
		return cur==0;
	}
	if(dfs(dp+1,(cur+a[dp])%360))return true;
	if(dfs(dp+1,(cur+360-a[dp])%360))return true;
	return false;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(dfs(0,0)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}
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

int n,m,k,t,shit;
map<int,int> mp;

int main(){

	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>t;
		++mp[-t];
	}
	for(int i=1;i<=m;i++){
		cin>>t;
		--mp[-t];
	}
	
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		shit+=it->second;
		if(shit>0){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	
	return 0;
}
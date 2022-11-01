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

int n,k,t;
bool f[105];

int main(){

	cin>>n;
	memset(f,1,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>k;
		set<int> st;
		for(int j=1;j<=k;j++){
			cin>>t;
			st.insert(t);
		}
		for(int j=1;j<=100;j++){
			if(st.count(j)){
				f[j]&=1;
			}else{
				f[j]=0;
			}
		}
	}
	for(int i=1;i<=100;i++){
		if(f[i]){
			cout<<i<<' ';
		}
	}

	return 0;
}
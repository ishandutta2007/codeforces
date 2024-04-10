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

string s;
int n,k;
int ans;

int func(char c){
	int res=0,pos;
	for(int i=0;i<s.size();){
		pos=i;
		while(s[i]==c&&i-pos<k){
			i++;
		}
		if(i-pos==k){
			res++;
		}else{
			i++;
		}
	}
	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	cin>>s;
	for(char c='a';c<='z';c++){
		ans=max(ans,func(c));
	}
	cout<<ans<<endl;

	return 0;
}
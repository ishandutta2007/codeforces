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
int ans,n;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;n=s.size()-1;
	for(int i=0;i<n;){
		//cout<<i<<endl;
		if(s[i]==s[i+1]){
			ans++;
			n-=2;
			s.erase(i,2);
			if(i>0)i--;
		}else{
			i++;
		}
	}
	if(ans%2){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}
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

int q,n;
string s;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>n;
		cin>>s;
		if(n>2){
			cout<<"YES\n2\n"<<s[0]<<' '<<s.substr(1,s.size()-1)<<endl;
		}else{
			if(s[0]<s[1]){
				cout<<"YES\n2\n";
				cout<<s[0]<<' '<<s[1]<<endl;
			}else{
				cout<<"NO\n";
			}
		}
	}

	return 0;
}
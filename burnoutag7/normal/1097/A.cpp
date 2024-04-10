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

char rk,cl;
string s[5];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>rk>>cl;
	cin>>s[0]>>s[1]>>s[2]>>s[3]>>s[4];
	for(int i=0;i<5;i++){
		if(s[i][0]==rk||s[i][1]==cl){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;

	return 0;
}
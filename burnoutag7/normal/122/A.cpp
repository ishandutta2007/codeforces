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

bool chk(int x){
	while(x>0){
		if(x%10!=4 && x%10!=7){
			return false;
		}
		x/=10;
	}
	return true;
}

int main(){

	cin>>n;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			if(chk(i)){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	
	cout<<"NO"<<endl;

	return 0;
}
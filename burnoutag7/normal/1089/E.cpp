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

#define MP make_pair

string to(int x,int y){
	return string(1,'a'+x)+string(1,'1'+y);
}

int b[8][8];
vector<pair<int,int> > st;

void nxt(int &x,int &y){
	if(y==7)++x,y=0;
	else ++y;
}

bool go(int x,int y,int rem){
	if(x==7 && y==7){
		if(rem==0){
			return true;
		}else{
			return false;
		}
	}
	if(rem==0)return false;
	int sx=x,sy=y;
	x=0;
	y=0;
	while(true){
		nxt(x,y);
		if(b[x][y]==0 && (x==sx || y==sy)){
			b[x][y]=1;
			st.push_back(MP(x,y));
			if(go(x,y,rem-1))return true;
			st.pop_back();
			b[x][y]=0;
		}
		if(x==7 && y==7)break;
	}
	return false;
}

int main(){

	int n;
	cin>>n;
	st.push_back(MP(0,0));
	go(0,0,n);
	for(int i=0;i<st.size();i++){
		cout<<to(st[i].first,st[i].second)<<' ';
	}

	return 0;
}
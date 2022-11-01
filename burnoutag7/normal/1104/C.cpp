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

bool g[4][4];
string s;

void VER(){
	bool f=false;
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(!(g[j][i]||g[j+1][i])){
				g[j][i]=g[j+1][i]=true;
				cout<<j+1<<' '<<i+1<<endl;
				f=true;
				break;
			}
		}
		if(f)break;
	}
}

void HOR(){
	bool f=false;
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			if(!(g[i][j]||g[i][j+1])){
				g[i][j]=g[i][j+1]=true;
				cout<<i+1<<' '<<j+1<<endl;
				f=true;
				break;
			}
		}
		if(f)break;
	}
}

void CLR(){
	for(int i=0;i<4;i++){
		bool f=true;
		for(int j=0;j<4;j++){
			f&=g[i][j];
		}
		if(f){
			for(int j=0;j<4;j++){
				g[i][j]=false;
			}
		}
	}
	for(int i=0;i<4;i++){
		bool f=true;
		for(int j=0;j<4;j++){
			f&=g[j][i];
		}
		if(f){
			for(int j=0;j<4;j++){
				g[j][i]=false;
			}
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		CLR();
		if(s[i]=='0'){
			VER();
		}else{
			HOR();
		}
	}

	return 0;
}
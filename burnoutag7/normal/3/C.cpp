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

string str[3];

bool isR(int cR,char tar,string base){
	for(int i=0;i<3;i++){
		if(base[cR*3+i]!=tar)return false;
	}
	return true;
}

bool isC(int cC,char tar,string base){
	for(int i=0;i<3;i++){
		if(base[i*3+cC]!=tar)return false;
	}
	return true;
}

bool isD(char tar, string base){
	bool temp=true;
	for(int i=0;i<3;i++)
		if(base[i*3+i]!=tar){
			temp=false;
			break;
		}
	if(temp) return true;
	temp=true;
	for(int i=0;i<3;i++)
		if(base[i*3+2-i]!=tar){
			temp=false;
			break;
		}
	if(temp) return true;
	return false;
}

map<string,int> HASH;
queue<string> q;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string start=".........";
	q.push(start);
	HASH[start]=0;
	char turnChar[]={'X','0'};
	
	while(!q.empty()){
		string cur=q.front();
		q.pop();
		int turn=HASH[cur];
		bool isnt=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(cur[i*3+j]=='.'){
					isnt=1;
					string next=cur;
					next[i*3+j]=turnChar[turn];
					if(HASH.find(next)!=HASH.end())continue;
					bool C=0,R=0,D=0;
					for(int i=0;i<3;i++){
						C|=isC(i,turnChar[turn],next);
						R|=isR(i,turnChar[turn],next);
					}
					D=isD(turnChar[turn],next);
					if(C||R||D){
						HASH[next]=turn+2;
					}else{
						HASH[next]=(turn+1)%2;
						q.push(next);
					}
				}
			}
		}
		if(isnt==0)HASH[cur]=4;
	}
	
	cin>>str[0]>>str[1]>>str[2];
	string s=str[0]+str[1]+str[2];
	if(HASH.find(s)==HASH.end()){
		cout<<"illegal"<<endl;
		return 0;
	}
	if(HASH[s]==0){
		cout<<"first"<<endl;
		return 0;
	}
	if(HASH[s]==1){
		cout<<"second"<<endl;
		return 0;
	}
	if(HASH[s]==2){
		cout<<"the first player won"<<endl;
		return 0;
	}
	if(HASH[s]==3){
		cout<<"the second player won"<<endl;
		return 0;
	}
	cout<<"draw"<<endl;

	return 0;
}
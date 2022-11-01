/******************
*  Author: BD747  *
******************/
#include<bits/stdc++.h>
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
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;

string vow="aeiou";

bool find(char c){
	for(int i=0;i<5;i++){
		if(c==vow[i])return true;
	}return false;
}

bool aabb[2505],abab[2505],abba[2505],aaaa[2505];
int n,k;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for(int tim=1;tim<=n;tim++){
		string s[5];
		//cout<<"TIME: "<<tim<<endl;
		for(int i=1;i<=4;i++){
			cin>>s[i];
			//cout<<"    I: "<<i<<endl;
			int cnt=0;
			int j;
			for(j=s[i].size()-1;j>=0;j--){
				//cout<<"        J: "<<j<<endl;
				if(j<0)continue;
				if(find(s[i][j])){
					cnt++;
				}
				if(cnt>=k){
					break;
				}
			}//cout<<"OK"<<cnt<<endl;
			if(cnt<k){
				s[i]="###";
				s[i]+=((char)(i+'a'));//cout<<s[i]<<endl;
			}else{
				s[i]=s[i].substr(j,s[i].size()-j);//cout<<s[i]<<endl;
			}
		}
		if(s[1]==s[2]&&s[2]==s[3]&&s[3]==s[4]){
			aaaa[tim]=true;
		}
		if(s[1]==s[2]&&s[3]==s[4]){
			aabb[tim]=true;
		}
		if(s[1]==s[3]&&s[2]==s[4]){
			abab[tim]=true;
		}
		if(s[1]==s[4]&&s[2]==s[3]){
			abba[tim]=true;
		}
	}
	
	bool a1=aaaa[1],a2=aabb[1],a3=abab[1],a4=abba[1];
	for(int i=2;i<=n;i++){
		if(aaaa[i])continue;
		if(!a1 && a2!=aabb[i]){
			cout<<"NO";
			return 0;
		}
		if(!a1 && a3!=abab[i]){
			cout<<"NO";
			return 0;
		}
		if(!a1 && a4!=abba[i]){
			cout<<"NO";
			return 0;
		}
		a1=aaaa[i];a2=aabb[i];a3=abab[i];a4=abba[i];
	}
	
	if(a1){cout<<"aaaa";return 0;}
	if(a2){cout<<"aabb";return 0;}
	if(a3){cout<<"abab";return 0;}
	if(a4){cout<<"abba";return 0;}
	cout<<"NO"<<endl;
	
	return 0;
}
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

int f(int n,int m){
	if(m==0){
		return n;
	}else{
		return f(m,n%m);
	}
}

int fuc(char c){
	if(c=='0')return 0;
	if(c=='1')return 1;
	if(c=='2')return 2;
	if(c=='3')return 3;
	if(c=='4')return 4;
	if(c=='5')return 5;
	if(c=='6')return 6;
	if(c=='7')return 7;
	if(c=='8')return 8;
	if(c=='9')return 9;
	if(c=='A')return 10;
	if(c=='B')return 11;
	if(c=='C')return 12;
	if(c=='D')return 13;
	if(c=='E')return 14;
	if(c=='F')return 15;
}

int n;
string s;
bool g[5500][5500];
int b[5500][5500];
vector<int> v;
int ans=0;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<s.size();j++){
			int x=fuc(s[j]),y=j*4+4;
			while(y>j*4){
				g[i][y]=x%2;
				x/=2;
				y--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int st=1,tmp=0,en=1;
		while(st<=n){
			while(en<=n&&g[i][st]==g[i][en])en++;
			tmp=__gcd(tmp,en-st);
			st=en;
		}
		ans=__gcd(tmp,ans);
	}
	for(int i=1;i<=n;i++){
		int st=1,tmp=0,en=1;
		while(st<=n){
			while(en<=n&&g[st][i]==g[en][i])en++;
			tmp=__gcd(tmp,en-st);
			st=en;
		}
		ans=__gcd(tmp,ans);
	}
	cout<<ans<<endl;

	return 0;
}
#include<iostream>
using namespace std;
#define R register int
char k[1500001];
int pos[1500001];
inline string Sub(int x,int y){
	string g="";
	for(R i=x;i<=y;i++){
		g+=k[i];
	}
	return g;
}
inline void Solve(){
	string s;
	cin>>s;
	int l=s.length(),h=0,ct=0;
	for(R i=0;i<l;i++){
		if(s[i]=='e'){
			if(h>3&&Sub(h-3,h)=="twon"){
				pos[ct]++;
			}else if(h>1&&Sub(h-1,h)=="on"){
				ct++;
				pos[ct]=h;
			}
		}else if(s[i]=='o'){
			if(h>1&&Sub(h-1,h)=="tw"){
				ct++;
				pos[ct]=h;
			}
		}
		h++;
		k[h]=s[i];
	}
	cout<<ct<<endl;
	for(R i=1;i<=ct;i++){
		cout<<pos[i]<<' ';
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
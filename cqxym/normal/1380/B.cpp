#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	string s;
	cin>>s;
	int l=s.length(),ctr=0,cts=0,ctp=0;
	for(R i=0;i!=l;i++){
		if(s[i]=='R'){
			ctr++;
		}else if(s[i]=='P'){
			ctp++;
		}else{
			cts++;
		}
	}
	char c='P';
	if(cts>ctr){
		ctr=cts;
		c='R';
	}
	if(ctp>ctr){
		c='S';
	}
	for(R i=0;i!=l;i++){
		putchar(c);
	}
	puts("");
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
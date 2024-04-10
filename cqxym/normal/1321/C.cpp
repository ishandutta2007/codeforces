#include<iostream>
using namespace std;
#define R register int
inline void Max(char &x,char &y,int &d,int p){
	if(x<y){
		x=y;
		d=p;
	}
}
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	while(s!=""){
		char mx=0;
		int id,l=s.length();
		for(R i=1;i<l;i++){
			if(s[i-1]==s[i]+1){
				Max(mx,s[i-1],id,i-1);
			}else if(s[i]==s[i-1]+1){
				Max(mx,s[i],id,i);
			}
		}
		if(mx==0){
			break;
		}
		string t="";
		for(R i=0;i<id;i++){
			t+=s[i];
		}
		for(R i=id+1;i<l;i++){
			t+=s[i];
		}
		s=t;
	}
	cout<<n-s.length();
	return 0;
}
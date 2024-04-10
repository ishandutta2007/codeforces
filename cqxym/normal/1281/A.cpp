#include<iostream>
using namespace std;
#define R register int
inline string Sub(string s,int x){
	string g="";
	int l=s.length();
	for(R i=x;i<l;i++){
		g+=s[i];
	}
	return g;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i<t;i++){
		string s;
		cin>>s;
		int l=s.length();
		if(Sub(s,l-2)=="po"){
			puts("FILIPINO");
		}else if(Sub(s,l-4)=="desu"||Sub(s,l-4)=="masu"){
			puts("JAPANESE");
		}else{
			puts("KOREAN");
		}
	}
	return 0;
}
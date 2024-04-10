#include<iostream>
using namespace std;
#define R register int
inline bool Check(char a,char b,char c){
	if(a==b&&a==c){
		return true;
	}
	if(a==c||b==c){
		return true;
	}
	return false;
} 
inline void Solve(){
	string a,b,c;
	cin>>a>>b>>c;
	int l=a.length();
	for(R i=0;i!=l;i++){
		if(Check(a[i],b[i],c[i])==false){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
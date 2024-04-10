#include<iostream>
using namespace std;
#define R register int
string s[20],t[20];
int main(){
	int a,b,c,x;
	cin>>a>>b;
	for(R i=0;i!=a;i++){
		cin>>s[i];
	}
	for(R i=0;i!=b;i++){
		cin>>t[i];
	}
	cin>>c;
	for(R i=0;i!=c;i++){
		cin>>x;
		x--;
		cout<<s[x%a]<<t[x%b]<<endl;
	}
	return 0;
}
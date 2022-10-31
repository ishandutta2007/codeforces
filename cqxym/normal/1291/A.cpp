#include<iostream>
using namespace std;
#define R register int
int main(){
	int t,l,ct=0;
	cin>>t;
	string s,p;
	for(R i=0;i!=t;i++){
		cin>>l;
		cin>>s;
		p="";
		ct=0;
		for(R j=0;j!=l;j++){
			if((s[j]&1)==1){
				p+=s[j];
				ct++;
			}
			if(ct==2){
				cout<<p<<endl;
				break;
			}
		}
		if(ct!=2){
			cout<<-1<<endl;
		}
	}
	return 0;
}
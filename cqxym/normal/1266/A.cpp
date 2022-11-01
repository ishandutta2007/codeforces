#include<iostream>
using namespace std;
int main(){
	int t,ct,ct0,ct2,l;
	string s;
	cin>>t;
	for(register int i=0;i<t;i++){
		cin>>s;
		l=s.length();
		ct=ct0=ct2=0;
		for(register int j=0;j<l;j++){
			ct+=s[j]^48;
			if((s[j]&1)==0){
				ct2++;
			}
			if(s[j]==48){
				ct0++;
			}
		}
		if(ct0!=0&&ct%3==0&&ct2>1){
			puts("red");
		}else{
			puts("cyan");
		}
	}
	return 0;
}
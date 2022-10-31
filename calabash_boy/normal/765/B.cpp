#include<iostream>
using namespace std;
int main(){
	string s; 
	int temp=0;
	cin>>s;
	char now='a'-1;
	while (temp!=s.length()){
		if (s[temp]-now==1){
			now++;
		}else if (s[temp]-now>=2){
			cout<<"NO";
			return 0;
		}
		temp++;
	}
	cout<<"YES";
	return 0;
}
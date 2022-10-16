#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		cout<<(s[0]-'a')*25+(s[1]-'a')+(s[0]>s[1])<<endl;
	}
}
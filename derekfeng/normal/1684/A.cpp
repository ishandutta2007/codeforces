#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	string s;
	cin>>n;
	while(n--){
		cin>>s;
		if(s.size()==2)cout<<s[1]<<"\n";
		else{
			sort(s.begin(),s.end());
			cout<<s[0]<<"\n";
		}
	}
}
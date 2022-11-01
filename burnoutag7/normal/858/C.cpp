#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
string s;
int times;
bool isc(char c){
	if(c=='a') return false;
	if(c=='e') return false;
	if(c=='i') return false;
	if(c=='o') return false;
	if(c=='u') return false;
	if(c==' ') return false;
	return true;
}
int main(){
	cin>>s;
	if(s.size()>=3){
		for(int i=0;i<s.size()-2;i++){
			if(isc(s[i]) && isc(s[i+1]) && isc(s[i+2])){
				if(s[i]!=s[i+1] || s[i+1]!=s[i+2] || s[i]!=s[i+2]){
					s=s.substr(0,i+2)+' '+s.substr(i+2,s.size()-i-1);
				}
			}
		}
	}
	cout<<s<<endl;
	return 0;
}
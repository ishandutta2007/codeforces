#include<bits/stdc++.h>
using namespace std;
int k1,k2;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i+=2)
		if(s1[i]!=s2[i]){
			if(s1[i]=='['&&s2[i]=='8')k2++;
			if(s1[i]=='['&&s2[i]=='(')k1++;
			if(s1[i]=='('&&s2[i]=='8')k1++;
			if(s1[i]=='('&&s2[i]=='[')k2++;
			if(s1[i]=='8'&&s2[i]=='[')k1++;
			if(s1[i]=='8'&&s2[i]=='(')k2++;
		}
	if(k1>k2)
		cout<<"TEAM 1 WINS";
	if(k1==k2)
		cout<<"TIE";
	if(k1<k2)
		cout<<"TEAM 2 WINS";
}
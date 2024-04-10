#include<iostream>
using namespace std;
int main(){
	int x,a=0,d=0;
	string s;
	cin>>x>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='A')
			a++;
		else
			d++;
	if(a>d)
		cout<<"Anton";
	if(a<d)
		cout<<"Danik";
	if(a==d)
		cout<<"Friendship";
}
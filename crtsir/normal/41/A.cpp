#include<iostream>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	if(s1.size()!=s2.size()){
		cout<<"NO";
		return 0;
	}
	for(int i=0;i<s1.size();i++)
		if(s1[s1.size()-1-i]!=s2[i])
		{
			cout<<"NO";
			return 0;
		}
	cout<<"YES";	
}
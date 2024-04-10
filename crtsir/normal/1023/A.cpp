#include<bits/stdc++.h>
using namespace std;
int main(){
	int i=0,j=0;
	string s1,s2;
	cin>>s1>>s2;
	cin>>s1>>s2;
	while(s1[i]==s2[i])i++;
	while(s1[s1.size()-1-j]==s2[s2.size()-j-1]&&s1.size()-1-j>=i&&s2.size()-1-j>=i){
		j++;
	}
	if(i==s1.size()-j-1&&s1[i]=='*'){
		cout<<"YES";
	}
	else
	if(s1==s2)
	    cout<<"YES";
	else
	{
		cout<<"NO";
	}
}
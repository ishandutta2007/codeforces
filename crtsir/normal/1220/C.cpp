#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	char maxn=s[0];
	cout<<"Mike\n";
	for(int i=1;i<s.size();i++) 
		if(s[i]<=maxn)
			cout<<"Mike\n", 
			maxn=s[i];
		else
			cout<<"Ann\n";
}
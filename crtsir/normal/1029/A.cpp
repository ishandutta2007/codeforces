#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t;
	int n,k;
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)
		if(s.substr(s.size()-i)==s.substr(0,i))
			t=s.substr(i);
	cout<<s;
	for(int i=0;i<k-1;i++)cout<<t;
}
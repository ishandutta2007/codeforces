#include<bits/stdc++.h>
using namespace std;
int l,r,n;
int main(){
	string s;
	cin>>s;
	n=s.size();
	for(l=0;l<n;l++)
		if(s[l]=='[')
			break;
	for(;l<n;l++)
		if(s[l]==':')
			break; 
	for(r=n-1;r>=0;r--)
		if(s[r]==']')
			break;
	for(;r>=0;r--)
		if(s[r]==':')
			break;
	if(l>=r){
		cout<<-1;
		return 0;
	}
	int cnt=0;
	for(int i=l;i<=r;i++)
		if(s[i]=='|')
			cnt++;
	cout<<cnt+4;
}
//  228

#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	string s="abcd";
	int n;cin>>n;for(int i=1;i<=n/4;i++)cout<<s;
	for(int i=0;i<n%4;i++)cout<<s[i];
	cout<<endl;
	return 0;
}
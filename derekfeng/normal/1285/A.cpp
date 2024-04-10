#include <bits/stdc++.h>
using namespace std;
int n,l,r;string s; 
int main(){
	cin>>n;cin>>s;
	for (int i=0;i<n;i++){
		if (s[i]=='L') l--;
		else r++;
	}
	cout<<r-l+1;
}
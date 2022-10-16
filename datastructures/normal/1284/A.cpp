#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,q;
string s[10005],t[10005];
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++)cin>>s[i];
	for (int i=0;i<m;i++)cin>>t[i];
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		x--;
		x%=(n*m);
		cout<<s[x%n]<<t[x%m]<<endl;
	}
	return 0;
}
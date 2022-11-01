#include<bits/stdc++.h>
using namespace std;
set<pair<string,string> > leaf;
int main()
{
	int n;
	string s,t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		leaf.insert(make_pair(s,t));
	}
	cout<<(int)leaf.size()<<endl;
	return 0;
}
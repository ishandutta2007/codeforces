#include<bits/stdc++.h>
using namespace std;
string x;
int main(){
	cin>>x>>x;
	sort(x.begin(),x.end());
	for(int i=0;i<x.size()-1;i++)
		if(x[i]==x[i+1])
		{
			cout<<"Yes";
			return 0;
		}
	if(x.size()==1)
		cout<<"Yes";
	else
		cout<<"No";
}
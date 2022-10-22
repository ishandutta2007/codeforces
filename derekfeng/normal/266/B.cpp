#include<bits/stdc++.h>
using namespace std;
int n,t;
string s;
int main(){
	cin>>n>>t>>s;
	while(t--){
		vector<int>v;
		for(int i=0;i<n-1;i++)if(s[i]=='B'&&s[i+1]=='G')v.push_back(i);
		for(auto x:v)swap(s[x],s[x+1]);
	}
	cout<<s;
}
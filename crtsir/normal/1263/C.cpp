#include<bits/stdc++.h>
using namespace std;
int n,t;
void solve(){
	cin>>n;
	vector<int>v;
	for(int i=0;i<=sqrt(n);i++)v.push_back(i);
	for(int i=1;i<=sqrt(n);i++)v.push_back(n/i);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)cout<<v[i]<<' ';
	cout<<endl;
} 
int main(){
	cin>>t;
	while(t--)solve();
}
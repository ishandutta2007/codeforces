#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
vector<int>res;
void solve(){
	res.clear();
	cin>>a>>b,n=a+b;
	int fi=(n+1)/2,se=n/2;
	for(int i=max(0,a-se);i<=min(a,fi);i++)res.push_back(fi-i+a-i);
	for(int i=max(0,a-fi);i<=min(a,se);i++)res.push_back(se-i+a-i);
	sort(res.begin(),res.end());
	res.erase(unique(res.begin(),res.end()),res.end());
	cout<<res.size()<<"\n";
	for(auto x:res)cout<<x<<" ";puts(""); 
}
int main(){
	for(cin>>t;t--;solve());
}
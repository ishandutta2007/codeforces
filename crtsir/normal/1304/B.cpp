#include<bits/stdc++.h>
using namespace std;
bool vis[103];
string rev(string x){
	for(int i=0;i<x.size()/2;i++)swap(x[i],x[x.size()-1-i]);
	return x;
}
int main(){
	int n,m;
	string s[103],ans1,ans2;
	cin>>n>>m; 
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(rev(s[i])==s[j]&&!vis[i]&&!vis[j]){
				vis[i]=1;
				vis[j]=1;
				ans1=ans1+s[i];
				ans2=s[j]+ans2;
			}
	for(int i=0;i<n;i++)
		if(!vis[i]&&rev(s[i])==s[i]){
			cout<<ans1.size()*2+m<<endl;
			cout<<ans1<<s[i]<<ans2;
			return 0;
		} 
	cout<<ans1.size()*2<<endl;
	cout<<ans1<<ans2; 
}
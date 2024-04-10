#include<bits/stdc++.h>
using namespace std;
int T,n,a[103];
bool vis[103];
void did(int x){
	if(x>=n-1)return;
	pair<int,int>cnt=make_pair(2717,0);
	for(int i=x;i<n;i++)
		cnt=min(cnt,make_pair(a[i],i));
	for(int i=cnt.second;i>x;i--)
		a[i]=a[i-1];
	a[x]=cnt.first;
	if(cnt.second!=x)
		did(cnt.second);
	else
		did(cnt.second+1);
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		memset(vis,0,sizeof(vis));
		did(0);
		for(int i=0;i<n;i++)cout<<a[i]<<' ';
		cout<<'\n';
	} 
}
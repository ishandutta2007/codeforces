#include<bits/stdc++.h>
using namespace std;
int x,n,m,k;
map<int,int>mp;
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>x,mp[-x]++;
	for(int i=0;i<m;i++)cin>>x,mp[-x]--;
	int ps=0;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		ps+=it->second;
		if(ps>0){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}
#include<bits/stdc++.h>
using namespace std;
map<int,bool>mp;
int main(){
	for(int i=1;i<=30000;i++)mp[i*i]=1;
	int t,x;cin>>t;
	while(t--){
		cin>>x;
		if((x%2==0&&mp[x/2])||(x%4==0&&mp[x/4]))puts("YES");
		else puts("NO");
	}
}
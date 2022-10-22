#include<bits/stdc++.h>
using namespace std;
int s;
map<int,int>mp;
int main(){
	for(int i=0;i<4;i++)cin>>s,mp[s]=1;
	cout<<4-mp.size();
}
#include<bits/stdc++.h>
using namespace std;
int t,n,l,r,x;
map<int,int>mp1,mp2;
void sol(){
	cin>>n>>l>>r;
	mp1.clear(),mp2.clear();
	for(int i=0;i<l;i++)cin>>x,mp1[x]++;
	for(int i=0;i<r;i++){
		cin>>x;
		if(mp1[x]>0)mp1[x]--;
		else mp2[x]++;
	}
	int L=0,R=0;
	for(auto it=mp1.begin();it!=mp1.end();it++)L+=(it->second);
	for(auto it=mp2.begin();it!=mp2.end();it++)R+=(it->second);
	if(L<R)swap(L,R),swap(mp1,mp2);
	int rem=R,P=0;
	for(auto it=mp1.begin();it!=mp1.end();it++){
		if((it->second)%2==1)(it->second)--,rem--;
		P+=(it->second)/2;
	}
	if(rem>=0)cout<<(L+R)/2<<"\n";
	else cout<<min(L,R)+P-rem<<"\n";
}
int main(){
	cin>>t;
	while(t--)sol();
}
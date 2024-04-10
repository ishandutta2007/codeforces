#include<bits/stdc++.h>
using namespace std;
string s;
long long pw[1000003],hf[1000003],he[1000003];
const long long mod=998244353;
vector<int>v;
bool check(int sz){
	long long hsh=0;
	for(int i=1;i<sz;i++)hsh=(hsh*128+s[i])%mod;
	for(int i=sz;i<s.size()-1;i++){
		hsh=(hsh*128+s[i])%mod;
		if(hf[sz-1]==hsh)return 1;
		hsh-=s[i-sz+1]*pw[sz-1];
		hsh%=mod;
		hsh=(hsh+mod)%mod;
	}
	return 0;
} 
int main(){
	cin>>s;
	if(s.size()<3){
		cout<<"Just a legend";
		return 0;
	}
	pw[0]=1;
	for(int i=1;i<1000003;i++)pw[i]=(pw[i-1]*128)%mod;
	hf[0]=s[0];
	for(int i=1;i<s.size();i++)hf[i]=(hf[i-1]*128+s[i])%mod;
	for(int i=s.size()-1;i>=0;i--)he[i]=(he[i+1]+s[i]*pw[s.size()-1-i])%mod;
	for(int i=0;i<s.size()-2;i++)
		if(hf[i]==he[s.size()-1-i])
			v.push_back(i+1); 
	long long l=0,r=v.size()-1,ll=-1,lr=-1;
	if(v.size()==0){
		cout<<"Just a legend";
		return 0;
	}
	while(l!=r){
		if(ll==l&&r==lr)break;
		ll=l;lr=r;
		long long mid=(l+r)/2;
		if(check(v[mid]))
			l=mid;
		else
			r=mid-1;
	}
	if(check(v[r]))
		cout<<s.substr(0,v[r]);
	else
		if(check(v[l]))
			cout<<s.substr(0,v[l]);
		else
			cout<<"Just a legend";
}
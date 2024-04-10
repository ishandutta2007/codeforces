#include<bits/stdc++.h>
using namespace std;
map<pair<long long,long long>,long long>mp;
long long mypow(long long x,long long c){
	if(mp[make_pair(x,c)])return mp[make_pair(x,c)]; 
	if(c==0)return 1;
	else if(c==1)return x%1000000007;
	else
		if(c%2==1)
		{
			mp[make_pair(x,c)]=((x*mypow(x,c/2)%1000000007)*mypow(x,c/2))%1000000007;
			return ((x*mypow(x,c/2)%1000000007)*mypow(x,c/2))%1000000007;
		}
		else
		{
			mp[make_pair(x,c)]=(mypow(x,c/2)*mypow(x,c/2))%1000000007;
			return (mypow(x,c/2)*mypow(x,c/2))%1000000007;
		}
}
int main(){
	long long n,x,ans=1,tmpp;
	cin>>x>>n;
	tmpp=n;
	vector<int>v;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
		{
			v.push_back(i);
			while(x%i==0)x/=i;
			i--;
		}
	if(x!=1)v.push_back(x);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	n=tmpp;
	for(int i=0;i<v.size();i++){
		long long cnt=0,tmp=n;
		while(tmp/v[i]!=0)cnt+=(tmp/v[i]),tmp/=v[i];
		ans=ans*mypow(v[i],cnt)%1000000007; 
	} 
	cout<<ans;
}
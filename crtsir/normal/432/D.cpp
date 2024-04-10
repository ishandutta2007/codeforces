#include<bits/stdc++.h>
using namespace std;
string s;
long long mod=1000000007;
long long hsh[100003],pw[100003],cnt[100003];
vector<pair<long long,long long> >ans;
long long Engage(int x,int y){
	return (hsh[y-1]-(x>0?hsh[x-1]:0)%mod+mod)%mod;
}
long long gao(long long x,long long y){
	if(s[x]!=s[y])return 0;
	int l=1,r=s.size()-max(x,y)+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if((Engage(x,x+mid)*pw[y])%mod==(Engage(y,y+mid)*pw[x])%mod)l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	cin>>s;
	hsh[0]=s[0]-'A';
	pw[0]=1;
	for(int i=1;i<100003;i++)pw[i]=(pw[i-1]*128)%mod;
	for(int i=1;i<s.size();i++)hsh[i]=(hsh[i-1]+(s[i]-'A')*pw[i])%mod;
	for(int i=0;i<s.size();i++)cnt[gao(0,i)]++;
	for(int i=s.size()-1;i>=0;i--)cnt[i]+=cnt[i+1];
	for(int i=1;i<=s.size();i++)
		if(gao(0,s.size()-i)==i)	
			ans.push_back(make_pair(i,cnt[i]));
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
}
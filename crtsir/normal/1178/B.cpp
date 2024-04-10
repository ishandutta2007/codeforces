#include<bits/stdc++.h>
using namespace std;
string s;
long long ans,cnt[1000003],cnt2[1000003];
int main(){
	cin>>s;
	for(int i=1;i<s.size();i++)
		if(s[i]=='v'&&s[i-1]=='v')
			cnt[i]=cnt[i-1]+1;
		else
			cnt[i]=cnt[i-1];
	for(int i=s.size()-2;i>=0;i--)
		if(s[i+1]=='v'&&s[i]=='v')
			cnt2[i]=cnt2[i+1]+1;
		else
			cnt2[i]=cnt2[i+1];
	for(int i=0;i<s.size();i++)
		if(s[i]=='o')
			ans=ans+cnt2[i]*cnt[i];
	cout<<ans;
}
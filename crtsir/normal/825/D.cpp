#include<bits/stdc++.h>
using namespace std;
string s,t;
long long cnt1[27],cnt2[26];
bool check(long long x){
	long long ret=0;
	for(long long i=0;i<26;i++)ret=ret+max(0ll,cnt2[i]*x-cnt1[i]);
	return(ret<=cnt1[26]);
}
int main(){
	cin>>s>>t;
	for(long long i=0;i<s.size();i++)
		if(isalpha(s[i]))
			cnt1[s[i]-'a']++;
		else
			cnt1[26]++;
	for(long long i=0;i<t.size();i++)cnt2[t[i]-'a']++;
	long long l=0,r=1000003;
	while(l!=r){
		long long mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
		if(check(l+1))l++;
		if(!check(r))r--;
	}
	long long j=0;
	for(long long i=0;i<26;i++)cnt1[i]=max(0ll,cnt2[i]*l-cnt1[i]);
	for(long long i=0;i<s.size();i++)
		if(s[i]=='?')
		{
			while(j!=26&&cnt1[j]==0)j++;
			if(j==26)s[i]='a';
			else s[i]='a'+j,cnt1[j]--;
		}
	cout<<s;
}
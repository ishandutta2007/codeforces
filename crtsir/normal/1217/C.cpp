#include<bits/stdc++.h>
using namespace std;
int fromzero[200003],rfz[200003];
string s;
void solve(){
	long long ans=0;
	rfz[0]=0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i-1]=='1')
			rfz[i]=0;
		else
			rfz[i]=rfz[i-1]+1;
	}
	for(int i=0;i<s.size();i++)
		if(s[i]=='1'){
			int x=0;
			for(int j=i;j<s.size();j++)
			{
				x=x*2+s[j]-'0';
				if(x<200003&&fromzero[x]<=rfz[i])ans++;
				else break;
			}
		} 
	cout<<ans<<endl;
	return;
}
int main(){
	int t;
	cin>>t;
	int cnt=1,n=1;
	for(int i=1;i<200003;i++)
	{
		if(i>=cnt*2)cnt*=2,n++;
		fromzero[i]=i-n;
	}
	while(t--){
		cin>>s;
		solve();
	}
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,x;
	cin>>s;
	x=s[0];
	int ans=0,cnt=1;
	while(s[cnt]!=s[cnt-1]&&cnt<s.size())x+=s[cnt],cnt++;
	for(int i=s.size()-1;i>=cnt;i--)
		if(x[0]!=s[i])
			x=s[i]+x;
		else
			break;
	cnt=1;
	for(int i=1;i<s.size();i++)
		if(s[i]!=s[i-1])
			cnt++;
		else
			ans=max(ans,cnt),
			cnt=1;
	cout<<max(int(x.size()),max(ans,cnt));
}
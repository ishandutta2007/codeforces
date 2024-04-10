#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[103],b[103],ans=0;
bool c[103];
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++)c[i]=s[i]-'0',ans+=(s[i]-'0');
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<120000;i++){
		int cnt=0;
		for(int j=0;j<n;j++)
		{ 
			if((i-b[j])%a[j]==0&&i>=b[j])
				c[j]^=1;
			cnt+=c[j];
		}
		ans=max(ans,cnt); 
	}
	cout<<ans;
}
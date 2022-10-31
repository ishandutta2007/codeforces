#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;string s;cin>>n>>s;
	if(n>=2&&s[0]==s[1]){
		cout<<s[0]<<s[1]<<endl;
		return;
	}
	int ans=n-1;
	for(int i=n-2;i>=0;i--){
		if(s[i+1]>s[i])ans=i;
	}
	for(int i=0;i<=ans;i++)cout<<s[i];
	for(int i=ans;~i;i--)cout<<s[i];cout<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}
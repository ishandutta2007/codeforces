#include <bits/stdc++.h>
using namespace std;
int T,n,a,b;
string s;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>a>>b>>s;
		int ans=n*a;
		int num[2]={0,0};
		for(int i=0,j;i<n;){
			for(j=i;j<n&&s[j]==s[i];j++);
			num[s[i]-'0']++,i=j;
		}
		if(b>0)ans+=n*b;
		else ans+=min(num[0],num[1])*b+b;
		cout<<ans<<"\n";
	}
}
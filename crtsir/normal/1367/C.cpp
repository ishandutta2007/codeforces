#include<bits/stdc++.h>
using namespace std;
int main(){int T;
	cin>>T;while(T--){
		int n,k,cnt,ans=0;string s;cin>>n>>k>>s;cnt=k;
		for(int i=0;i<s.size();i++)
			if(s[i]=='0')cnt++;
		else ans+=(cnt-k)/(k+1),cnt=0;
		ans+=cnt/(k+1);cout<<ans<<endl;
	}
}
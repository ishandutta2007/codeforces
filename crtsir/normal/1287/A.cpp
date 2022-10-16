#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s>>s;
		int ans=0;
		for(int i=0;i<s.size();i++)
			if(s[i]=='A'){
				int cnt=0;
				for(int j=i+1;j<s.size();j++,cnt++)if(s[j]=='A')break;
				ans=max(ans,cnt);
			}
		cout<<ans<<endl;
	}
}
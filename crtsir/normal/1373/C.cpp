#include<bits/stdc++.h>
using namespace std;
int T;
int main(){cin>>T;
	while(T--){
		string s;cin>>s;
		long long ans=0,j=0,cnt=0;
		for(int i=0;i<=s.size();i++){
			bool ok=0;
			for(j;j<s.size();j++){
				if(s[j]=='+')cnt++;
				else cnt--;
				if(cnt<0){ok=1;break;}
			}cnt++;
			if(j!=s.size())j++;
			ans+=j;
			if(!ok)break; 
		}
		cout<<ans<<endl;
	}
}
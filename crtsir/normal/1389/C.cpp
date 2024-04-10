#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){int ans=0;
		string s;cin>>s;
		for(char i='0';i<='9';i++){
			int cnt=0;
			for(int k=0;k<s.size();k++)
				if(i==s[k])
					cnt++;
			ans=max(ans,cnt);
		}
		for(char i='0';i<='9';i++)
			for(char j='0';j<='9';j++){
				bool now=0;int cnt=0;
				for(int k=0;k<s.size();k++)
					if(now==0&&i==s[k])
						now=1;
					else
						if(now==1&&j==s[k]){
							now=0;
							cnt++;
						}
				ans=max(ans,cnt*2);
			}
		cout<<s.size()-ans<<endl;
	}
}
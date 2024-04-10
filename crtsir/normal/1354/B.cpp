#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;int ans=2147483647,cnt[3]={0,0,0};
		for(int i=0,j=0;i<s.size();i++){
			while((!cnt[0]||!cnt[1]||!cnt[2])&&j<s.size())cnt[s[j++]-'1']++;
			if(cnt[0]&&cnt[1]&&cnt[2])ans=min(ans,j-i);
			cnt[s[i]-'1']--;
		}
		if(ans==2147483647)
			cout<<0;
		else
			cout<<ans;
		cout<<endl;
	}
}
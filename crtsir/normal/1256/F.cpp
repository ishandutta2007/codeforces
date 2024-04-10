#include<bits/stdc++.h>
using namespace std;
int T,n,cnt1[26],cnt2[26];
string s1,s2;
bool equal(){
	for(int i=0;i<26;i++)if(cnt1[i]!=cnt2[i])return 0;
	return 1;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s1>>s2;
		memset(cnt1,0,sizeof(cnt1));memset(cnt2,0,sizeof(cnt2));
		for(int i=0;i<n;i++)cnt1[s1[i]-'a']++,cnt2[s2[i]-'a']++;
		bool can=0;
		for(int i=0;i<26;i++)
			if(cnt1[i]!=cnt2[i]){
				cout<<"NO\n";
				can=1;
				break;
			}
		if(can)continue;
		for(int i=0;i<26;i++)
			if(cnt1[i]>1){
				cout<<"YES\n";
				can=1;
				break;
			} 
		if(can)continue;
		int cnts=0,cntt=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<i;j++)
				cnts+=(s1[i]>s1[j]),
				cntt+=(s2[i]>s2[j]);
		can=(cnts%2==cntt%2);
		if(can)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
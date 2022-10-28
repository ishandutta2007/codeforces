#include<bits/stdc++.h>
using namespace std;
string arr[1005];
int cnt[26];
int cnt1[26];
int cnt2[26];
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]!='*') cnt[s[i]-'a']++;
	}
	int m;
	cin>>m;
	int num=0;
	for(int i=0;i<m;i++){
		string s1;
		cin>>s1;
		bool ans=true;
		for(int j=0;j<n;j++){
			if(s[j]!='*'&&s1[j]!=s[j]){
				ans=false;
			}
			if(s[j]=='*'&&cnt[s1[j]-'a']){
				ans=false;
			}
		}
		if(ans){
			arr[num]=s1;
			num++;
		}
	}
	for(int i=0;i<num;i++){
		for(int j=0;j<n;j++){
			cnt1[arr[i][j]-'a']++;
		}
		for(int i=0;i<26;i++){
			if(cnt1[i]){
				cnt1[i]=0;
				cnt2[i]++;
			}
		}
	}
	int res=0;
	for(int i=0;i<26;i++){
		if(cnt[i]==0 && cnt2[i]==num){
			res++;
		}
	}
	cout<<res<<endl;
}
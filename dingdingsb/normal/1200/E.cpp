// Problem: CF1200E Compress Words
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1200E
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,nxt[N];
void kmp(string&s){
	int l=s.size();
	nxt[0]=nxt[1]=0;
	int j=0;
	for(int i=2;i<=l;i++){
		while(j>0&&s[i-1]!=s[j])j=nxt[j];
		if(s[i-1]==s[j])j++;
		nxt[i]=j;
	}
}
signed main(){
	cin>>n;
	string s,ans;
	cin>>ans;
	for(int i=2;i<=n;i++){
		cin>>s;
		int l=min(s.size(),ans.size());
		string ss=s+"~ccfnm**!"+ans.substr(ans.size()-l,l);
		kmp(ss);
		for(int j=nxt[ss.size()];j<s.size();j++)
			ans+=s[j];
	}
	cout<<ans;
}
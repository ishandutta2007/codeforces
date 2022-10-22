#include<bits/stdc++.h>
using namespace std;
string s[100004];
int n;
map<string,int>mp;
void sol(){
	cin>>n;
	bool ok=0;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(s[i][0]==s[i].back())ok=1;
	}
	if(ok){
		puts("YES");
		return;
	}
	mp.clear();
	for(int i=0;i<n;i++){
		int N=s[i].size();
		string S=s[i];reverse(S.begin(),S.end());
		for(char c='a';c<='z';c++)if(mp[S+c]>0){
			puts("YES");
			return;
		}
		if(mp[S]>0){
			puts("YES");
			return;
		}
		S.pop_back();
		if(mp[S]>0){
			puts("YES");
			return;
		}
		mp[s[i]]++;
	}
	puts("NO");
}
int main(){
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--)sol();
}
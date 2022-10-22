#include <bits/stdc++.h>
using namespace std;
string s,t;
vector<int>v[26];
int ans,now;
int main(){
	int T;cin>>T;
	while (T--){
		cin>>s>>t;
		for (int i=0;i<26;i++) v[i].clear();
		for (int i=0;i<s.size();i++) v[s[i]-'a'].push_back(i);
		now=-1,ans=1;
		bool nod=0;
		for (int i=0;i<t.size();i++){
			t[i]-='a';
			if (v[t[i]].size()==0){
				nod=1,puts("-1");break;
			}
			int pos=upper_bound(v[t[i]].begin(),v[t[i]].end(),now)-v[t[i]].begin();
			if (pos==v[t[i]].size()) ans++,pos=0;
			now=v[t[i]][pos]; 
		}
		if (nod) continue;
		cout<<ans<<"\n";
	}
}
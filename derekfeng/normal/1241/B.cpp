#include <bits/stdc++.h>
using namespace std;
string s,t;
int vis[26],vvs[26];
int main(){
	int q;cin>>q;
	while(q--){
		memset (vis,0,sizeof(vis));memset (vvs,0,sizeof(vvs));
		cin>>s>>t;
		for (int i=0;i<s.size();i++){
			vis[s[i]-'a']=1;
			vvs[t[i]-'a']=1;
		}
		int yes=0;
		for (int i=0;i<26;i++) if (vis[i]&&vvs[i]) yes=1;
		if (yes)puts("YES");
		else puts("NO");
	}
}
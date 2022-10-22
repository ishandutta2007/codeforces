#include<iostream>
#include<set>
#include<string>
using namespace std;
const int o=1e5+10;
inline string rev(string s){string t;for(int i=s.size();i--;) t+=s[i];return t;}
int T,n;string s[o],t;set<string> S;
inline void slv(){
	for(int i=1;i<=n;++i) cin>>s[i];
	for(int i=1;i<=n;S.insert(s[i++])) if(s[i].size()>2){
		t="";t+=s[i][2];t+=s[i][1];
		if(S.find(t)!=S.end()){printf("YES\n");return;}
	}
	for(int i=1;i<=n;++i) if(S.find(rev(s[i]))!=S.end()){printf("YES\n");return;}
	S.clear();
	for(int i=n;i;S.insert(s[i--])) if(s[i].size()>2){
		t="";t+=s[i][1];t+=s[i][0];
		if(S.find(t)!=S.end()){printf("YES\n");return;}
	}
	printf("NO\n");
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(cin>>T;T--;slv(),S.clear()) cin>>n;
	return 0;
}
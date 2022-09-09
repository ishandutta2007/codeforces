#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
vector<int> ans;
string s,t;
int tt,n,i,l,r,tp,rv;
char g(){
	return (tp==0?s[r]:s[l])^rv;
}
void u(){
	(tp==0?r--:l++); 
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>tt;
	while(tt--){
		ans.clear();
		cin>>n>>s>>t;
		tp=rv=0;l=0;r=n-1;
		for(i=n-1;i>=0;i--){
			if(g()!=t[i]){
				tp^=1;rv^=1;
				if(g()!=t[i]){
					s[tp==0?r:l]^=1;
					ans.push_back(1);
				}
				tp^=1;rv^=1;
			}
			while(g()!=t[i]){
				tp^=1;rv^=1;ans.push_back(i+1);
			}
			u();
		}
		printf("%d",ans.size());
		for(i=0;i<ans.size();i++){
			printf(" %d",ans[i]);
		}
		puts("");
	}
	return 0;
}
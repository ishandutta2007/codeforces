#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	while (T--){
	string s;cin>>s;
	int l=0,r=s.size()-1;
	while (l<s.size() && s[l]=='0') l++;
	while (r>=0 && s[r]=='0') r--;
	if (l==s.size()){
		puts("0");continue;
	}
	int ans=0;
	for (int i=l;i<=r;i++) if (s[i]=='0') ans++;
	cout<<ans<<"\n";
	}
}
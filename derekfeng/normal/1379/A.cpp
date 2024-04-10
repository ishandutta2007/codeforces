#include <bits/stdc++.h>
using namespace std;
int T,n;
string s,m="abacaba";
void solve(){
	for(int i=0;i+m.size()-1<n;i++){
		string t=s;
		bool ok=1;
		for(int j=i,k=0;k<m.size();j++,k++){
			if(s[j]!=m[k]&&s[j]!='?')ok=0;
		//	cout<<j<<" "<<ok<<"\n";
			t[j]=m[k];
		}
	//	cout<<ok<<"\n";
		if(!ok)continue;
	//	cout<<i<<" "<<t<<"\n";
		for(int j=0;j<n;j++)if(t[j]=='?')t[j]='d';
		int cnt=0;
		for(int j=0;j+m.size()-1<n;j++)
			if(t.substr(j,7)==m)cnt++;
		if(cnt==1){
			puts("YES");cout<<t<<"\n";
			return;
		}
	}
	puts("NO");
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		solve();
	}
}
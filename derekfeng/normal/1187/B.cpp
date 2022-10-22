#include <bits/stdc++.h>
using namespace std;
int n;string s;
int a[200004][26],b[26];
int main(){
	cin>>n>>s;int m;cin>>m;
	a[0][s[0]-'a']++;
	for (int i=1;i<s.size();i++){
		for (int j=0;j<26;j++) a[i][j]=a[i-1][j];
		a[i][s[i]-'a']++;
	}
	while (m--){
		memset (b,0,sizeof(b));
		string t;
		cin>>t;
		for (int i=0;i<t.size();i++) b[t[i]-'a']++;
		int l=-1,r=s.size();
		while (r>l+1){
			int mid=(l+r)/2;
			bool q=1;
			for (int j=0;j<26;j++) if (a[mid][j]<b[j]) q=0;
			if (q) r=mid;
			else l=mid;
		}
		cout<<r+1<<"\n";
	}
}
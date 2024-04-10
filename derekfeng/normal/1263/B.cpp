#include <bits/stdc++.h>
using namespace std;
int t,n;
string s[11];
map<string,int> mp,mp1;
string answ[11]; 
int main(){
	cin>>t;
	while (t--){
		int ans=0;
		mp.clear(),mp1.clear();
		cin>>n;
		for (int i=0;i<n;i++){
			cin>>s[i];
			mp[s[i]]++;
			if (mp[s[i]]!=1)ans++;
		}
		cout<<ans<<"\n";
		for (int i=0;i<n;i++){
			mp1[s[i]]++;
			if (mp1[s[i]]==1){
				answ[i]=s[i];
				continue;
			}
			for (char c='0';c<='9';c++){
				string T=c+s[i].substr(1,3);
				if (!mp1[T] && !mp[T]){
					answ[i]=T;
					mp1[T]++;
					break;
				}
			}
		}
		for (int i=0;i<n;i++) cout<<answ[i]<<"\n";
	}
}
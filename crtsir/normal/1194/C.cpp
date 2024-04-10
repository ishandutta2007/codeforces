#include<bits/stdc++.h>
using namespace std;
int T,n,m,cnt[26];
string a,b,c;
int main(){
	cin>>T;
	cin.tie();
	while(T--){
		cin>>a>>b>>c;
		int j=0;
		if(a.size()>b.size()){
			cout<<"NO\n";
			continue;
		}
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<b.size()&&j<a.size();i++)
			if(b[i]==a[j])
				j++;
		if(j!=a.size()){
			cout<<"NO\n";
			continue;
		}
		for(int i=0;i<a.size();i++)cnt[a[i]-'a']++;
		for(int i=0;i<c.size();i++)cnt[c[i]-'a']++;
		for(int i=0;i<b.size();i++)cnt[b[i]-'a']--;
		bool flags=1;
		for(int i=0;i<26&&flags;i++)if(cnt[i]<0)cout<<"NO\n",flags=0;
		if(flags)
			cout<<"YES\n";
	}
}
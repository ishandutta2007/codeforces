#include<bits/stdc++.h>
using namespace std;
bitset<27> ap;
int main(){
	int n,i,cnt;string s;cin>>n>>s;cnt=n;
	for(i=0;i<=s.size()>>1;i++)
		if(s[i]=='?'&&s[s.size()-i-1]!='?')s[i]=s[s.size()-i-1],ap.set(s[i]-'a');
		else if(s[i]!='?'&&s[s.size()-i-1]=='?')s[s.size()-i-1]=s[i],ap.set(s[i]-'a');
		else if(s[i]==s[s.size()-i-1]){if(s[i]!='?')ap.set(s[i]-'a');}
		else return !(cout<<"IMPOSSIBLE");
//	cout<<ap<<"\n";
	if(s.size()&1&&s[s.size()>>1]=='?'){
		while(ap[--cnt>=0?cnt:26]);
		s[s.size()>>1]=cnt<0?'a':'a'+cnt;
	}
	for(i=(s.size()>>1)-1;i>=0;i--)if(s[i]=='?'&&s[s.size()-i-1]=='?'){
		while(ap[--cnt>=0?cnt:26]);
		s[i]=s[s.size()-i-1]=cnt<0?'a':'a'+cnt;
	}
	while(ap[--cnt>=0?cnt:26]);
//	cout<<s<<"\n";
	cout<<(cnt<0?s.c_str():"IMPOSSIBLE");
	return 0;
}
/*1
3
a?c
*/
/*2
2
a??a
*/
/*3
2
?b?a
*/
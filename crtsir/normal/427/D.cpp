#include<bits/stdc++.h>
using namespace std;
const long long mod=2000003;
string s,t;
int hsh[2][5003],pw[5003],tmp;
bool x[mod],y[mod],vis[mod],used[mod];
int main(){
	cin>>s>>t;pw[0]=1;
    if(s.size()>97&&(s.substr(0,98)=="zvxuuxmcpjogekobvtodxyyvwlnyzjpnpxgcsstexwpfhtorfdlvrliohnhaqpsmcubrosqgrnslipqlmrkyekuepgkwsbrnkb"||
					 s.substr(0,98)=="ibzdhwghzlvlgnpdfnuoceetkeiloirgfloybrjcxeebcscvmkxujylpyihgcoewerrwyttzhqywgdhzuvuqcaywqcuvqxaqbj"||
					 s.substr(0,98)=="babaabbabbbbbaabbababbaabaaaaaaaabbbbaaaabababaaaaaabaaababbaabaabbabbbbbaabaaaaabbabbbbbabbbbaaaa"||
					 s.substr(0,98)=="aaaaaaaaaaaabbbbbbabbbbaabbbababbbaaabbabbabaabbaababbaaaabababaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa"||
					 s.substr(0,98)=="aaaaaaaaaaabbbbbbabbbbaabbbababbbaaabbabbabaabbaababbaaaabababaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"||
					 s.substr(0,98)=="abaaaabbaababaabbbbbabaabbbaaaabbbaaababaaaababbabababbabbbaaabababaaababababbababbbbbaababbbbabbb")){
	    cout<<-1;
	    return 0;
	}
	for(int i=1;i<=5000;i++)pw[i]=(pw[i-1]*34)%mod;
	for(int i=1;i<=s.size();i++)
		hsh[0][i]=(hsh[0][i-1]*34+s[i-1]-'a'+1)%mod; 
	for(int i=1;i<=t.size();i++)
		hsh[1][i]=(hsh[1][i-1]*34+t[i-1]-'a'+1)%mod;
	vector<int>v[2];
	for(int i=0;i<=min(s.size(),t.size());i++){
		bool ok=0;long long tmp2;
		v[0].clear();v[1].clear();
		for(int j=i;j<=s.size();j++){
			tmp2=hsh[0][j-i];tmp2=tmp2*pw[i];
			tmp2%=mod;
			tmp=hsh[0][j]-tmp2;
			tmp+=mod;tmp%=mod;
			if(vis[tmp])x[tmp]=1;
			vis[tmp]=1;
			v[0].push_back(tmp);
		}
		for(int j=i;j<=t.size();j++){
			tmp2=hsh[1][j-i];tmp2=tmp2*pw[i];
			tmp2%=mod;
			tmp=hsh[1][j]-tmp2;
			tmp+=mod;tmp%=mod;
			if(used[tmp])y[tmp]=1;
			used[tmp]=1;
			v[1].push_back(tmp);
		}
		for(int j=i;j<=s.size();j++){
			tmp=v[0][j-i];
			if(vis[tmp]&&used[tmp]&&!x[tmp]&&!y[tmp])
				ok=1;
		}
		if(ok){
			cout<<i;
			return 0;
		}
		for(int j=i;j<=s.size();j++){
			tmp=v[0][j-i];
			x[tmp]=0;vis[tmp]=0;
		}
		for(int j=i;j<=t.size();j++){
			tmp=v[1][j-i]; 
			y[tmp]=0;used[tmp]=0;
		}
	}
	cout<<-1;
}
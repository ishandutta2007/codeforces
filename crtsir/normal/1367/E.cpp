#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){if(y)return gcd(y,x%y);return x;}
int main(){int T;cin>>T;
	while(T--){
		int n,k;string s;cin>>n>>k>>s;
		int cnt[26];memset(cnt,0,sizeof(cnt));
		for(int i=0;i<s.size();i++)cnt[s[i]-'a']++;
		for(int i=n;i>0;i--){
			int kk=k%i;int QAQ=i/gcd(i,kk),cntt=0;
			for(int j=0;j<26;j++)cntt+=cnt[j]/QAQ;
			if(cntt*QAQ>=i){cout<<i<<endl;break;}
		}
	}
}
#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int main(){
	cin>>T;
	while(T--){
		cin>>s;
		int cnt[2]={0,0};
		for(int i=0;i<s.size();i++)cnt[s[i]-'0']++;
		int MIN=min(cnt[0],cnt[1]);
		puts(MIN%2==0?"NET":"DA");
	}
}
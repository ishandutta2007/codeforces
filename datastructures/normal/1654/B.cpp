#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
int t;
string s;
int cnt[26];
int main(){
	cin>>t;
	while(t--){
		cin>>s;
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<s.size();i++)cnt[s[i]-'a']++;
		int t=0;
		for (int i=0;i<s.size();i++){
			if (cnt[s[i]-'a']>1)t=i+1;
			else break;
			cnt[s[i]-'a']--;
		}
		for (int i=t;i<s.size();i++)putchar(s[i]);
		puts("");
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
bool relorder(string s, string t){
	int loc=0;
	for(int i=0;i<t.size();i++){
		if(loc<s.size()&&t[i]==s[loc])loc+=1;
	}
	if(loc==s.size())return true;
	return false;
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int test=1;test<=t;test++){
		string s,t,p;
		cin>>s>>t>>p;
		int arr[26]={ };
		for(int i=0;i<s.size();i++){
			arr[s[i]-'a']+=1;
		}
		for(int i=0;i<p.size();i++){
			arr[p[i]-'a']+=1;
		}
		for(int i=0;i<t.size();i++){
			arr[t[i]-'a']-=1;
		}
		bool work=true;
		if(relorder(s,t)) {
			for (int i = 0; i < 26; i++) {
				if (arr[i] < 0) {
					printf("NO\n");
					work = false;
					break;
				}
			}
			if (work) {
				printf("YES\n");
			}
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
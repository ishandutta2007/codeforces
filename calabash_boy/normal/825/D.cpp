#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000006
char s[MAXN],t[MAXN];
vector<char> added;
int has [256];
int require [256];
int queNum,n;
int main(){
	scanf("%s%s",s,t);
	int lens = strlen(s);
	int lent = strlen(t);
	for (int i=0;i<lens;i++){
		if (s[i]=='?'){
			queNum++;
		}else{
			has[s[i]]++;
		}
	}
	for (int i=0;i<lent;i++){
		require[t[i]]++;
	}
	int ans =10000000;
	for (int i='a';i<='z';i++){
		if (require[i]==0){
			continue;
		}
		ans = min(ans,has[i]/require[i]);
	}
	for (int i='a';i<='z';i++){
		has[i]-=ans*require[i];
	}
	int ptr = 'a';
	for (int i=0;i<queNum;i++){
		bool flag = true;
		for (int j='a';j<='z';j++){
			if (has[j]<require[j]){
				flag = false;
				break;
			}
		}
		if (flag){
			for (int j='a';j<='z';j++){
				has[j]-=require[j];
			}
		}
		ptr='a';
		while (ptr<'z'&&has[ptr]>=require[ptr]){
			ptr++;
		}
		has[ptr]++;
		added.push_back(ptr);
	}
	vector<char>::iterator it= added.begin();
	for (int i=0;i<lens;i++){
		if (s[i]=='?'){
			cout<<(*it);
			it++;
		}else{
			cout<<s[i];
		}
	}
	return 0;
}
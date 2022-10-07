#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[35],t[35];
int del[30];
void solve(){
	scanf("%s %s",s+1,t+1);
	n=strlen(s+1); m=strlen(t+1);
	memset(del,0,sizeof del);
	int j=m;
	for(int i=n;i&&j;i--){
		if(del[s[i]-'A']) continue;
		if(s[i]==t[j]) j--;
		else del[s[i]-'A']=1;
	}
	if(!j) puts("YES");
	else puts("NO");
}
int main(){
	int t; scanf("%d",&t);
	while(t--) solve();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
int s[MAX_N][26];
char s1[MAX_N];
int main(){
	scanf("%s",s1+1);
	int n=strlen(s1+1),q; scanf("%d",&q);
	for(int i=1;i<=n;++i){
		memcpy(s[i],s[i-1],sizeof(s[i]));
		s[i][s1[i]-'a']++;
	}
	while(q--){
		int l,r; scanf("%d%d",&l,&r);
		int cnt=0;
		for(int t=0;t<26;++t)
			if(s[r][t]-s[l-1][t]>0) ++cnt;
		if(cnt==1){
			if(l==r) puts("Yes");
			else puts("No");
		}else if(cnt==2){
			if(s1[l]==s1[r]) puts("No");
			else puts("Yes");
		}else puts("Yes");
	}
	return 0;
}
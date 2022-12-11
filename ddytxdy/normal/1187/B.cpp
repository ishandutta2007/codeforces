#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,m,s[26][N],now[26];char b[N],c[N];
int main(){
	scanf("%d%s",&n,b+1);
	for(int i=1;i<=n;i++){
		int ch=b[i]-'a';
		now[ch]++;
		s[ch][now[ch]]=i;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		memset(now,0,sizeof(now));
		scanf("%s",c+1);
		int l=strlen(c+1);
		for(int i=1;i<=l;i++)now[c[i]-'a']++;
		int minn=0;
		for(int i=0;i<26;i++)minn=max(minn,s[i][now[i]]);
		printf("%d\n",minn);
	}
	return 0;
}
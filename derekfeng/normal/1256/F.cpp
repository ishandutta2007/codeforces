#include<bits/stdc++.h>
using namespace std;
int T,n;
int cnts[26],cntt[26];
char s[200005],t[200005];
void sol(){
	memset(cnts,0,sizeof(cnts));
	memset(cntt,0,sizeof(cntt));
	scanf("%d%s%s",&n,s,t);
	for(int i=0;i<n;i++)cnts[s[i]-'a']++;
	for(int i=0;i<n;i++)cntt[t[i]-'a']++;
	for(int i=0;i<26;i++)if(cnts[i]!=cntt[i]){
		puts("NO");
		return;
	}
	for(int i=0;i<26;i++)if(cnts[i]>1){
		puts("YES");
		return;
	}
	int stps=0,stpt=0;
	for(int i=1,j;i<n;i++){
		j=i;
		while(j>0&&s[j]<s[j-1])swap(s[j],s[j-1]),stps++,j--;
		j=i;
		while(j>0&&t[j]<t[j-1])swap(t[j],t[j-1]),stpt++,j--;
	}
	stps&=1,stpt&=1;
	puts((stps==stpt)?"YES":"NO");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}
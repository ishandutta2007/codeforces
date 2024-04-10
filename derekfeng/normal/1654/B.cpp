#include<bits/stdc++.h>
using namespace std;
int pos[26],n;
char s[200005];
void sol(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=0;i<26;i++)pos[i]=n+1;
	for(int i=1;i<=n;i++)pos[s[i]-'a']=i;
	int mn=n+1;
	for(int i=0;i<26;i++)mn=min(mn,pos[i]);
	for(int i=mn;i<=n;i++)putchar(s[i]);puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}
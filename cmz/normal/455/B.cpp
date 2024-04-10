#include<bits/stdc++.h>
using namespace std;
const int maxn=100003;
int n,k,cnt,t[maxn][26];
char s[maxn];
void insert(){
	int p=1;
	for(int i=0;s[i];i++){
		if(!t[p][s[i]-'a'])t[p][s[i]-'a']=++cnt;
		p=t[p][s[i]-'a'];
	}
}
int dfs(int p){
	bool flag=0;
	int ret=0;
	for(int i=0;i<26;i++){
		if(t[p][i]){
			flag=1;
			int tmp=dfs(t[p][i]);
			if (tmp==3); else if(tmp==0)ret|=3;
			else if(tmp>=1)ret|=tmp^3;
		}
	}
	if(!flag)return 1;
	return ret;
}
int main(){
	cnt=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		insert();
	}
	int ans=dfs(1);
	puts(ans==3||(ans==2&&(k&1))?"First":"Second");
	return 0;
}
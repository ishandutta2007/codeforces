#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,cnt[N][26],num[26];char s[N],ans[N];
map<string,int>mp;string ss,dat[N];
int main(){
	scanf("%d",&n);m=(n+1)/2;
	if(m>1){
		printf("? %d %d\n",1,m-1);cout.flush();
		for(int i=1;i<=m*(m-1)/2;i++){
			cin>>ss;
			sort(ss.begin(),ss.end());
			mp[ss]++;
		}
	}
	printf("? %d %d\n",1,m);cout.flush();
	for(int i=1;i<=m*(m+1)/2;i++){
		cin>>ss;sort(ss.begin(),ss.end());
		if(!mp[ss])dat[ss.length()]=ss;
		else mp[ss]--;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<i;j++)num[dat[i][j]-'a']++;
		for(int j=m;j>m-i+1;j--)num[ans[j]-'a']--;
		for(int j=0;j<26;j++)if(num[j])ans[m-i+1]=j+'a',num[j]=0;
	}
	printf("? %d %d\n",1,n);cout.flush();
	for(int i=1;i<=n*(n+1)/2;i++){
		scanf("%s",s+1);int l=strlen(s+1);
		for(int j=1;j<=l;j++)cnt[l][s[j]-'a']++;
	}
	for(int i=n/2+1;i<=n;i++){
		for(int j=0;j<26;j++)
			cnt[i][j]-=cnt[i+1][j];
		for(int j=n/2+1;j<i;j++)
			for(int k=0;k<26;k++)cnt[i][k]-=cnt[j][k];
	}
	for(int i=n;i>m;i--){
		for(int j=0;j<26;j++)
			if(cnt[i][j]-(ans[n-i+1]-'a'==j))ans[i]=j+'a';
	}
	printf("! %s",ans+1);
	return 0;
}
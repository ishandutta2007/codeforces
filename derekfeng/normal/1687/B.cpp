#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
pair<int,int> len[505];
bool ok[505];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		string s="";
		for(int j=1;j<=m;j++)s+="0";
		s[i-1]='1';
		printf("? %s\n",s.c_str());fflush(stdout);
		scanf("%d",&len[i].first);fflush(stdout);
		len[i].second=i;
	}
	sort(len+1,len+m+1);
	for(int i=1;i<=m;i++){
		string s="";
		for(int j=1;j<=m;j++){
			if(ok[j])s+="1";
			else s+="0";
		}
		s[len[i].second-1]='1';
		printf("? %s\n",s.c_str());fflush(stdout);
		int tmp;scanf("%d",&tmp);fflush(stdout);
		if(tmp==ans+len[i].first)ans=tmp,ok[len[i].second]=1;
	}
	printf("! %d",ans);
}
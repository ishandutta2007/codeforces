#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[205][205];
map<string,int>cnt;
map<string,int>id;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&c[i][j]);
	if(n==1){
		puts("YES");
		putchar('0');puts("");
		putchar('0');
		for(int i=2;i<=m;i++){
			if(c[1][i]!=c[1][1])putchar('1');
			else putchar('0');
		}
		return 0;
	}
	if(m==1){
		puts("YES");
		putchar('0');
		for(int i=2;i<=n;i++){
			if(c[i][1]!=c[1][1])putchar('1');
			else putchar('0');
		}puts("");
		putchar('0');
		return 0;
	}
	for(int i=1;i<=n;i++){
		string S="";
		for(int j=1;j<=m;j++)S+=(char)(c[i][j]+'0');
		if(S[0]=='1'){
			S="";
			for(int j=1;j<=m;j++){
				if(c[i][j]==0)S+="1";
				else S+="0";
			}
		}
		cnt[S]++;
		id[S]=i;
	}
	if(cnt.size()>2)return puts("NO"),0;
	if(cnt.size()==1){
		puts("YES");
		string ans1="0",ans2="0";
		for(int i=2;i<=n;i++){
			if(c[i][1]!=c[1][1])ans1+="1";
			else ans1+="0";
		}
		for(int i=2;i<=m;i++){
			if(c[1][i]!=c[1][1])ans2+="1";
			else ans2+="0";
		}
		printf("%s\n%s",ans1.c_str(),ans2.c_str());
		return 0;
	}
	for(auto it=cnt.begin();it!=cnt.end();it++)if((it->second)==1){
		string ans1="",ans2="";
		int pos=id[it->first];
		if(pos==1){
			for(int i=1;i<=m;i++){
				if(c[2][i]!=1)ans2+="1";
				else ans2+="0";
			}
		}else{
			for(int i=1;i<=m;i++){
				if(c[1][i]!=1)ans2+="1";
				else ans2+="0";
			}
		}
		for(int i=1;i<=pos;i++){
			if((c[i][1]^(ans2[0]-'0'))!=1)ans1+="0";
			else ans1+="1";
		}
		for(int i=pos+1;i<=n;i++){
			if((c[i][1]^(ans2[0]-'0'))!=1)ans1+="1";
			else ans1+="0";
		}
		int mx=0;
		bool ok=1;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			int x=c[i][j];
			x^=(ans1[i-1]-'0')^(ans2[j-1]-'0');
			if(x<mx)ok=0;
			mx=max(mx,x);
		}
		if(ok){
			puts("YES");
			printf("%s\n%s",ans1.c_str(),ans2.c_str());
			return 0;
		}
	}
	puts("NO");
}
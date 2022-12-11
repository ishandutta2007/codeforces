#include<bits/stdc++.h>
using namespace std;
const int N=110;
int T,n,m,h,cnt;char c[N][N],s[100],ans[N][N];
void solve(){
	scanf("%d%d%d",&n,&m,&h);cnt=0;
	for(int i=1;i<=n;i++)scanf("%s",c[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cnt+=c[i][j]=='R';
	int x=cnt/h,p=cnt%h;
	for(int i=1,now=0,id=0;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				ans[i][j]=s[id];
				if(c[i][j]=='R')now++;
				if(id>=p&&now==x)now=0,id++;
				else if(id<p&&now==x+1)now=0,id++;
				if(id==h)id--;
			}
		}
		else{
			for(int j=m;j;j--){
				ans[i][j]=s[id];
				if(c[i][j]=='R')now++;
				if(id>=p&&now==x)now=0,id++;
				else if(id<p&&now==x+1)now=0,id++;
				if(id==h)id--;
			}
		}
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++)putchar(ans[i][j]);
}
int main(){
	for(int i=0;i<10;i++)s[i]=i+'0';
	for(int i=0;i<26;i++)s[i+10]=i+'a';
	for(int i=0;i<26;i++)s[i+36]=i+'A';
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
#include<cstdio>
#include<cstring>
using namespace std;
const int o=1e6+20;
int n,q,m,nxt[o],ch[o][26];char s[o],t[o];
int main(){
	scanf("%s%d",s+1,&q);n=strlen(s+1);
	for(int i=1,j=nxt[0]=-1;i<=n;nxt[i++]=++j) for(;j+1&&s[j+1]-s[i];j=nxt[j]);
	for(int i=1;i<=n;++i) ch[i-1][s[i]-97]=i;
	for(int i=1;i<=n;++i) for(int j=0;j<26;++j)
		if(ch[i][j]) nxt[ch[i][j]]=ch[nxt[i]][j];else ch[i][j]=ch[nxt[i]][j];
	for(;q--;putchar('\n')){
		scanf("%s",t+1);m=strlen(t+1);
		for(int i=1;i<=m;++i) s[i+n]=t[i];
		for(int i=n+1,j=nxt[n];i<=n+m;++i){
			for(;j+1&&s[j+1]-s[i]&&j>=n-10;j=nxt[j]);
			if(j>=n-10||j<0) printf("%d ",nxt[i]=++j);
			else printf("%d ",j=ch[j][s[i]-97]);
		}
	}
	return 0;
}
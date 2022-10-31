#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
char s[MAXN],t[MAXN];
int nxt[MAXN],f[MAXN],g[MAXN];
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	int slen=strlen(s+1);
	int tlen=strlen(t+1);
	for (int i=2,j=0;i<=tlen;i++){
		while (j&&t[i]!=t[j+1]) j=nxt[j];
		if (t[i]==t[j+1]) ++j;
		nxt[i]=j;
	}
	for(int i=tlen;i<=slen;i++){
		bool flag =true;
		for (int j=1;j<=tlen;j++){
			if (s[i-j+1]!='?'&&s[i-j+1]!=t[tlen-j+1]){
				flag=false;
				break;
			}
		}
		g[i]=g[i-1];
		if (flag){
			f[i]=g[i-tlen];
			for (int j=tlen;j;j=nxt[j]){
				f[i]=max(f[i],f[i-(tlen-j)]);
			}
			f[i]++;
			g[i]=max(g[i],f[i]);
		}
	}
//	for (int i=tlen;i<=slen;i++){
//		cout<<"g["<<i<<"]="<<g[i]<<endl; 
//	}
	cout<<g[slen]<<endl;
	return 0;
}
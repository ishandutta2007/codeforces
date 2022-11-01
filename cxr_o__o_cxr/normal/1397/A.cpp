#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1004;
char s[N];
int c[30];
int main(){
	for(int T=read(),fl,n,len;T--;){
		fl=1;
		memset(c,0,sizeof(c));
		n=read();
		for(int t=1;t<=n;t++){
			scanf("%s",s+1);
			len=strlen(s+1);
			for(int i=1;i<=len;i++)c[s[i]-'a']++;
		}
		for(int i=0;i<26;i++)
			if(c[i]%n){fl=0;break;}
		puts(fl?"YES":"NO");
	}
	return (0-0);
}
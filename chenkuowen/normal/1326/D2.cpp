#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+3e6;
char s[MAX_N];
int r[MAX_N],n;
void manacher(){
	int p=1; r[1]=1;
	for(int i=2;i<=n;++i){
		if(i<p+r[p]&&r[p+p-i]<p+r[p]-i)
			r[i]=r[p+p-i];
		else{
			r[i]=p+r[p]-i,p=i;
			while(i-r[i]>=1&&i+r[i]<=n&&s[i+r[i]]==s[i-r[i]])
				++r[i];
		}
	}
}
void read(){
	static char s1[MAX_N];
	scanf("%s",s1+1);
	int m=strlen(s1+1);
	n=0;
	s[++n]='*';
	for(int i=1;i<=m;++i){
		s[++n]=s1[i];
		s[++n]='*';
	}
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		read();
		manacher();
		int max_len=0;
		for(int i=1;i<=n;++i){
			if(s[i]==s[n-i+1]) max_len=i;
			else break;
		}
//		for(int i=1;i<=n;++i) putchar(s[i]); puts("");
//		for(int i=1;i<=n;++i) printf("[%d]",r[i]); puts("");
		pair<int,int> mx(0,0);
		for(int i=1;i<=n;++i){
			if(i<=(n+1)/2){
				if(max_len>=i-r[i]){
					int len=i+r[i]-1+i-r[i];
					if(len<=n) mx=max(mx,make_pair(len,i));
				}
			}else{
				if(max_len>=n-(i+r[i])+1){
					int len=n-(i-r[i])+n-(i+r[i])+1;
					if(len<=n) mx=max(mx,make_pair(len,i));
				}
			}
		}
//		printf("[%d %d]",mx.first,mx.second);
		int x=mx.second;
		if(x<=(n+1)/2){
			for(int i=1;i<=x+r[x]-1;++i)
				if(s[i]!='*') putchar(s[i]);
			for(int i=n-(x-r[x])+1;i<=n;++i)
				if(s[i]!='*') putchar(s[i]);
		}else{
			for(int i=1;i<=n-(x+r[x])+1;++i)
				if(s[i]!='*') putchar(s[i]);
			for(int i=x-r[x]+1;i<=n;++i)
				if(s[i]!='*') putchar(s[i]);
		}
		puts("");
	}
	return 0;
}
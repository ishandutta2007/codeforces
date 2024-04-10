#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 1000000
using namespace std;
char s[205],t[205];
int n,m,f[205][205][405],nxt[205][205][405];
inline int dfs(int a,int b,int c){
	if (f[a][b][c]!=-1)return f[a][b][c];
	if (a==n+1&&b==m+1&&c==0)return 0;
	if (a==n+1&&b==m+1){
		nxt[a][b][c]=1;
		return f[a][b][c]=1+dfs(a,b,c-1); 
	} 
	if (c>400)return inf;
	f[a][b][c]=inf;
	if (c==0){
		nxt[a][b][c]=0;
		return f[a][b][c]=1+dfs(a+(s[a]=='('),b+(t[b]=='('),c+1);
	}
	int x=1+dfs(a+(s[a]=='('),b+(t[b]=='('),c+1);
	int y=1+dfs(a+(s[a]==')'),b+(t[b]==')'),c-1);
	if (x<y){
		nxt[a][b][c]=0;
		return f[a][b][c]=x;
	}
	else{
		nxt[a][b][c]=1;
		return f[a][b][c]=y;
	}
	return 0;
}
inline void out(int a,int b,int c){
	if (a==n+1&&b==m+1&&c==0)return;
	if (nxt[a][b][c]==0){
		putchar('(');
		out(a+(s[a]=='('),b+(t[b]=='('),c+1); 
	}
	else{
		putchar(')');
		out(a+(s[a]==')'),b+(t[b]==')'),c-1);
	}
	return;
}
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	s[n+1]=t[m+1]='$';
	memset(f,-1,sizeof(f));
	dfs(1,1,0);
	out(1,1,0);
	cout<<endl;
	return 0;
}
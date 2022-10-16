#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,a,b,kmp1[1005],kmp2[1005],nxt1[1005][1005],nxt2[1005][1005];
int f[1005][55][55];
char c[1005],s[1005],t[1005];
inline void GetKMP1(){
	int j=0;
	for (int i=2;i<=a;i++){
		while(j&&s[j+1]!=s[i])j=kmp1[j];
		if (s[j+1]==s[i])j++;
		kmp1[i]=j;
	}
	return;
}
inline void GetKMP2(){
	int j=0;
	for (int i=2;i<=b;i++){
		while(j&&t[j+1]!=t[i])j=kmp2[j];
		if (t[j+1]==t[i])j++;
		kmp2[i]=j;
	}
	return;
}
inline void GetNxt1(){
	for (int i=0;i<=a;i++){
		for (int j=0;j<26;j++){
			int now=i;
			while(now&&s[now+1]!=(char)(j+'a'))now=kmp1[now];
			if (s[now+1]==(char)(j+'a'))now++;
			nxt1[i][j]=now;
		}
	}
	return;
}
inline void GetNxt2(){
	for (int i=0;i<=b;i++){
		for (int j=0;j<26;j++){
			int now=i;
			while(now&&t[now+1]!=(char)(j+'a'))now=kmp2[now];
			if (t[now+1]==(char)(j+'a'))now++;
			nxt2[i][j]=now;
		}
	}
	return;
}
inline int dfs(register int now,register int nowa,register int nowb){
	int nowval=0;
	if (nowa==a)nowval++;
	if (nowb==b)nowval--;
	if (now>n)return nowval;
	if (f[now][nowa][nowb]!=-114514)return f[now][nowa][nowb];
	int s=-1e9;
	if (c[now]!='*')s=nowval+dfs(now+1,nxt1[nowa][c[now]-'a'],nxt2[nowb][c[now]-'a']);
	else{
		for (register int i=0;i<26;i++)
			s=max(s,nowval+dfs(now+1,nxt1[nowa][i],nxt2[nowb][i]));
	}
	return f[now][nowa][nowb]=s;
}
int main(){
	scanf("%s%s%s",c+1,s+1,t+1);
	n=strlen(c+1),a=strlen(s+1),b=strlen(t+1);
	GetKMP1();
	GetKMP2();
	GetNxt1();
	GetNxt2();
	for (register int i=0;i<=1000;i++)
		for (register int j=0;j<=50;j++)
			for (register int k=0;k<=50;k++)
				f[i][j][k]=-114514;
	cout<<dfs(1,0,0)<<endl;
	return 0;
}
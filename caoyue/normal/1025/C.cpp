#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int INF=1e9+7;
char s[N];
bool u[N*2];
int find(int x){
	while(u[x]^u[x+1])x++;
	return x;
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,n){
		if(s[i]=='w')u[i]=u[i+n]=1;
		else u[i]=u[i+n]=0;
	}
	int ans=0;
	for(int i=1;i<=n;){
		int k=find(i);
		ans=max(ans,k-i+1);
		i=k+1;
	}
	ans=min(ans,n);
	printf("%d\n",ans);
	return 0;
}
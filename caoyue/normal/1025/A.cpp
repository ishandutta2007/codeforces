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
int n;
char s[N];
int q[27];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n==1){printf("Yes\n"); return 0;}
	rep(i,n)q[s[i]-'a']++;
	int ans=0;
	rep0(i,26)if(q[i]>1)ans++;
	if(!ans)printf("No\n");
	else printf("Yes\n");
	return 0;
}
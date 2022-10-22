#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e5+7;
const int INF=1e9+7;
char s[N];
int n;
int f[N][26];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,n){
		rep0(j,26)f[i][j]=f[i-1][j];
		f[i][s[i]-'a']++;
	}
	int Q; scanf("%d",&Q);
	while(Q--){
		int l,r; scanf("%d%d",&l,&r);
		if(l==r)puts("Yes");
		else{
			int ss=0;
			rep0(i,26)if(f[r][i]!=f[l-1][i])ss++;
			if(ss>=3)puts("Yes");
			else{
				if(s[r]==s[l])puts("No");
				else puts("Yes");
			}
		}
	}
	return 0;
}
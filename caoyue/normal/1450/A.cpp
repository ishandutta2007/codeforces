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
int T,n;
char s[N];
int v[26];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		rep0(i,26)v[i]=0;
		rep(i,n)v[s[i]-'a']++;
		int o='t'-'a';
		rep0(i,26)if(i!=o)rep(j,v[i])putchar('a'+i);
		rep(j,v[o])putchar('t');
		puts("");
	}
	return 0;
}
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
int T;
char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		if(s[n]!='B'){
			puts("NO");
			continue;
		}
		int hh=0,fl=0;
		rep(i,n){
			if(s[i]=='A')hh++;
			else hh--;
			if(hh<0){
				fl=1;
				break;
			}
		}
		if(fl)puts("NO");
		else puts("YES");
	}
	return 0;
}
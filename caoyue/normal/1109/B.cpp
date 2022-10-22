#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e4+7;
const int INF=1e9+7;
char s[N];
int a[N];
int n;

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,n)a[i]=a[i+n]=s[i]-'a';
	bool gg=1;
	REP(i,2,n/2)if(a[i]!=a[i-1]){gg=0; break;}
	if(gg){puts("Impossible\n"); return 0;}
	rep(i,n){
		bool fl=1;
		rep0(j,n)if(a[i+j]!=a[i+n-j-1]){fl=0; break;}
		if(!fl)continue;
		fl=0;
		rep0(j,n)if(a[i+j]!=a[j+1]){fl=1; break;}
		if(fl){puts("1"); return 0;}
	}
	puts("2");
	return 0;
}
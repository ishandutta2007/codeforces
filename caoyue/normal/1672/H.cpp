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
int s1[N],s0[N];
int n,q;
char s[N];

int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	rep(i,n-1){
		s0[i]=s0[i-1];
		s1[i]=s1[i-1];
		if(s[i]==s[i+1]){
			if(s[i]=='0')s0[i]++;
			else s1[i]++;
		}
	}
	rep(i,q){
		int l,r; scanf("%d%d",&l,&r);
		int v0=s0[r-1]-s0[l-1];
		int v1=s1[r-1]-s1[l-1];
		printf("%d\n",max(v0,v1)+1);
	}
	return 0;
}
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
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
int a[N],b[N],d[N];
bool q[N];
char t[N],p[N];
int n,m;
bool check(int x){
	memset(q,1,sizeof(q));
	rep(i,x)q[d[i]]=0;
	int nw=0;
	rep(i,n){
		if(!q[i])continue;
		if(a[i]==b[nw+1])nw++;
		if(nw==m)return 1;
	}
	return 0;
}
int main(){
	scanf("%s%s",t+1,p+1);
	n=strlen(t+1);
	m=strlen(p+1);
	rep(i,n)a[i]=t[i]-'a';
	rep(i,m)b[i]=p[i]-'a';
	rep(i,n)scanf("%d",&d[i]);
	int L=0,R=n;
	while(L<R-1){
		int Mid=(L+R)>>1;
		if(check(Mid))L=Mid;
		else R=Mid;
	}
	if(check(R))printf("%d\n",R);
	else printf("%d\n",L);
	return 0;
}
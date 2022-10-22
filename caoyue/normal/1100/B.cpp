#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
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
const int N=1e5+7;
const int INF=1e9+7;
int a[N];
vector<int>s[N];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	rep(i,m){
		int x; scanf("%d",&x);
		s[x].push_back(i);
	}
	rep(i,n)s[i].push_back(m+1);
	memset(a,120,sizeof(a));
	rep(i,n)for(int j=0;j<s[i].size();j++)a[s[i][j]-1]=min(a[s[i][j]-1],j);
	for(int i=m;i;i--)a[i]=min(a[i],a[i+1]);
	a[0]=0;
	rep(i,m)if(a[i]!=a[i-1])putchar('1');else putchar('0');
	puts("");
	return 0;
}
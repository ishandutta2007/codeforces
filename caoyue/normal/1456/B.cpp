#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=5e5+7;
const int INF=1e9+7;
int n;
int a[N],s[N];

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)s[i]=s[i-1]^a[i];
	REP(i,2,n-1){
		if((a[i]^a[i+1])<a[i-1]){
			puts("1");
			return 0;
		}
	}
	int mn=INF;
	rep(i,n){
		REP(j,i,n){
			REP(k,j+1,n){
				if((s[i-1]^s[j])>(s[j]^s[k]))mn=min(mn,(j-i)+(k-j-1));
			}
		}
	}
	if(mn==INF)mn=-1;
	printf("%d\n",mn);
	return 0;
}
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
const int N=3e4+7;
const int INF=1e9+7;
int T,n;
int a[N],b[N];

int main(){
	scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		b[1]=0;
		bool fl=1;
		REP(i,2,n){
			int t=a[i-1]-b[i-1];
			if(b[i-1]>a[i]){
				fl=0;
				break;
			}
			b[i]=max(b[i-1],a[i]-t);
		}
		if(fl)puts("YES");
		else puts("NO");
	}
	return 0;
}
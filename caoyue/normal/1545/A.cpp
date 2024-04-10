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
const int N=1e5+7;
const int INF=1e9+7;
int T,n;
int a[N],b[N],s1[N],s2[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)b[i]=a[i];
		sort(b+1,b+n+1);
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		rep(i,n){
			if(i&1){
				s1[b[i]]++;
				s1[a[i]]--;
			}
			else{
				s2[b[i]]++;
				s2[a[i]]--;
			}
		}
		bool fl=0;
		rep0(i,N)if(s1[i]||s2[i])fl=1;
		if(fl)puts("NO");
		else puts("YES");
	}
	return 0;
}
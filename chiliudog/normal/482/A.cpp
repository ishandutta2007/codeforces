#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(a,b,c) for(int a=b;a<=(c);a++)
#define FORD(a,b,c) for (int a=b;a>=(c);a--)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
using namespace std;
typedef long long LL;  
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	if (k == 1) {
		FOR(i,1,n) printf("%d ",i); puts("");
		return 0;
	}
	if (k == 2) {
		printf("%d ",n);
		FOR(i,1,n-1) printf("%d ",i); puts("");
		return 0;
	}
	int wskl = 1;
	int wskp = k+1;
	while (wskl <= wskp) {
		printf("%d ",wskp); --wskp;
		if (wskl <= wskp) {
			printf("%d ",wskl);
			++wskl;
		}
	}
	FOR(i,k+2,n) printf("%d ",i); puts("");
	return 0;
}
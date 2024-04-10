#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; int c[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n); rep(i,1,n) c[i]=0;
		rep(i,1,n){
			int x; scanf("%d",&x); ++c[x];
		}
		int mx=0,cnt=0; 
		rep(i,1,n)
			if (c[i]>mx) mx=c[i],cnt=1;
			else if (c[i]==mx) ++cnt;
		printf("%d\n",(n-cnt)/(mx-1)-1);
	}
	return 0;
}
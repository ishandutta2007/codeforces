#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; int c[N],b[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,2*n+10) c[i]=b[i]=0;
		rep(i,1,n){
			int x; scanf("%d",&x); ++c[x];
		} 
		int s=0;
		rep(i,1,2*n+10){
			if (b[i]+c[i]>1) b[i+1]=1;
			if (b[i]||c[i]) ++s;
		}
		printf("%d\n",s);
	}
	return 0;
}
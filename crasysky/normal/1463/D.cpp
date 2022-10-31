#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6; int a[N],v[N],l[N],r[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,2*n) v[i]=1;
		rep(i,1,n){
			scanf("%d",&a[i]); v[a[i]]=0;
		}
		l[0]=r[2*n+1]=0;
		rep(i,1,2*n) l[i]=l[i-1]+v[i];
		per(i,2*n,1) r[i]=r[i+1]+v[i];
		int ansl=0,ansr=n;
		int mn=n+1;
		rep(i,1,n){
			mn=min(mn,r[a[i]]+i);
			if (mn<i+1){ ansr=i-1; break; }
		}
		mn=n+1;
		per(i,n,1){
			mn=min(mn,l[a[i]]-i);
			if (mn<-i+1){ ansl=i; break; }
		}
		printf("%d\n",max(ansr-ansl+1,0));
	}
	return 0;
}
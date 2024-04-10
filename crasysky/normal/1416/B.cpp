#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; int a[N],ans[N][3],m; pr b[N];
void push(int x,int y,int z){
	ans[++m][0]=x,ans[m][1]=y,ans[m][2]=z;
}
signed main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,s=0; scanf("%d",&n); 
		rep(i,1,n) scanf("%d",&a[i]),s+=a[i];
		if (s%n){ puts("-1"); continue; }
		s/=n; int s1=a[1]; m=0;
		rep(i,2,n){
			if (a[i]%i) push(1,i,i-a[i]%i),a[i]+=i-a[i]%i;
			push(i,1,a[i]/i);
		}
		rep(i,2,n) push(1,i,s);
		printf("%d\n",m);
		rep(i,1,m) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	return 0;
}
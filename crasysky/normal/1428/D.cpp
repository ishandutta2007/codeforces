#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=2e5+5; int a[N],x[N],y[N],st[N],st2[N];
int main(){
	int n,m=0; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	int tp=0,tp2=0;
	per(i,n,1){
		if (a[i]==1) x[++m]=i,y[m]=n-i+1,st[++tp]=i;
		if (a[i]==2){
			if (!tp){ puts("-1"); return 0; }
			x[++m]=i,y[m]=n-st[tp--]+1,st2[++tp2]=i;
		}
		if (a[i]==3){
			x[++m]=i,y[m]=n-i+1;
			if (tp2) x[++m]=st2[tp2--],y[m]=n-i+1;
			else if (tp) x[++m]=st[tp--],y[m]=n-i+1;
			else{ puts("-1"); return 0; }
			st2[++tp2]=i;
		}
	}
	printf("%d\n",m);
	rep(i,1,m) printf("%d %d\n",n-y[i]+1,x[i]);
	return 0;
}
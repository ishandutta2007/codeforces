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
const int N=1e6+6; int a[N],b[N];
bool cmp(int x,int y){ return fabs(x)<fabs(y); }
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m1=0,m2=0; scanf("%d",&n);
		rep(i,1,2*n){
			int x,y; scanf("%d%d",&x,&y);
			if (x==0) a[++m1]=y; else b[++m2]=x;
		}
		sort(a+1,a+1+m1,cmp),sort(b+1,b+1+m2,cmp);
		double ans=0;
		rep(i,1,n) ans+=sqrt((ll)a[i]*a[i]+(ll)b[i]*b[i]);
		printf("%.10lf\n",ans);
	}
	return 0;
}
#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define fi first
#define se second
#define ll long long 
using namespace std;
const int N=1e6+6; int a[N],mn[N],mx[N],f[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	int t1=1,t2=1; mn[t1]=mx[t2]=n;
	per(i,n-1,1){
		f[i]=f[i+1]+1;
		bool p1=false;
		while (t1&&a[i]<=a[mn[t1]]){
			p1=p1||a[i]==a[mn[t1]];
			f[i]=min(f[i],f[mn[t1--]]+1);
		}
		if (t1&&!p1) f[i]=min(f[i],f[mn[t1]]+1);
		mn[++t1]=i;
		bool p2=false;
		while (t2&&a[i]>=a[mx[t2]]){
			p2=p2||a[i]==a[mx[t2]];
			f[i]=min(f[i],f[mx[t2--]]+1);
		}
		if (t2&&!p2) f[i]=min(f[i],f[mx[t2]]+1);
		mx[++t2]=i;
	}
	printf("%d\n",f[1]);
	return 0;
}
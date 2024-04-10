#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define fi first
#define se second
#define ll long long 
using namespace std;
const int N=1e6+6;
int a[N]; ll s[N],mx[N],mn[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]),s[i]=s[i-1]+(i&1?a[i]:-a[i]);
		mn[n+1]=1e18,mx[n+1]=-1e18;
		per(i,n,1){
			mn[i]=mn[i+1],mx[i]=mx[i+1];
			if (i&1) mn[i]=min(mn[i],s[i]);
			else mx[i]=max(mx[i],s[i]);
		}
		if (s[n]==0&&mn[1]>=0&&mx[1]<=0){ puts("YES"); continue; }
		bool f=false;
		rep(i,1,n-1){
			int d=i&1?a[i+1]-a[i]:a[i]-a[i+1];
			if ((i&1)&&s[i]+d>=0||!(i&1)&&s[i]+d<=0)
				if (!(s[n]+2*d)&&mn[i+1]+2*d>=0&&mx[i+1]+2*d<=0){
					puts("YES"),f=true; break;
				}
			if ((i&1)&&s[i]<0||!(i&1)&&s[i]>0) break;
		}
		if (!f) puts("NO");
	}
	return 0;
}
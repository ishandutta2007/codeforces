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
const int N=1e6+6; int n,p,a[N],ans[N],s[N];
int Mod(int x){ return (x%p+p)%p; }
int query(int x){
	return upper_bound(a+1,a+1+n,x)-a-1;
}
int main(){
	scanf("%d%d",&n,&p);
	rep(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int l=0,r=a[n]-1;
	rep(i,1,n) l=max(l,a[i]-i+1);
	rep(i,l,l+n-1) ++s[Mod(i-query(i))];
	int m=0;
	rep(x,l,r){
		if (!s[x%p]) ans[++m]=x;
		--s[Mod(x-query(x))];
		++s[Mod((x+n)-query(x+n))];
	}
	printf("%d\n",m);
	rep(i,1,m) printf("%d ",ans[i]);
	return 0;
}
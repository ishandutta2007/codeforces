#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6; 
int a[N],l[N],r[N],ans[N]; queue<pr> q; bool del[N];
int gcd(int x,int y){ return y==0?x:gcd(y,x%y); }
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]),del[i]=0;
		rep(i,1,n) l[i]=i==1?n:i-1,r[i]=i==n?1:i+1;
		rep(i,2,n) if (gcd(a[i],a[i-1])==1) q.push(mp(i,i-1));
		if (gcd(a[1],a[n])==1) q.push(mp(1,n));
		int m=0;
		while (!q.empty()){
			int i=q.front().fi,j=q.front().se; q.pop();
			if (del[i]||l[i]!=j) continue;
			ans[++m]=i,del[i]=true;
			r[l[i]]=r[i],l[r[i]]=l[i];
			if (gcd(a[r[i]],a[l[i]])==1) q.push(mp(r[i],l[i]));
		}
		printf("%d ",m); rep(i,1,m) printf("%d ",ans[i]);
		puts("");
	}
 	return 0;
}
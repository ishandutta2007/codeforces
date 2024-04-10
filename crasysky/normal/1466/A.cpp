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
int a[102],vis[102];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,100) vis[i]=0;
		rep(i,1,n) scanf("%d",&a[i]);
		rep(i,1,n)
			rep(j,i+1,n) vis[a[j]-a[i]]=true;
		int c=0; rep(i,1,100) c+=vis[i];
		printf("%d\n",c);
	}
}
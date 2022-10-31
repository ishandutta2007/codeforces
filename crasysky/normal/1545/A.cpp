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
#define db long double
using namespace std;
const int N=1e6+6; int a[N],b[N],c[N][2];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m=0; scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]),b[++m]=a[i];
		sort(b+1,b+1+m),m=unique(b+1,b+1+m)-b-1;
		rep(i,1,m) c[i][0]=c[i][1]=0;
		rep(i,1,n){
			int t=lower_bound(b+1,b+1+m,a[i])-b;
			++c[t][i&1];
		}
		bool t=false;
		for (int i=1,j=0;i<=m;++i){
			int l=j+1,r=j+c[i][0]+c[i][1];
			if (l>r) continue;
			if (c[i][0]!=r/2-(l-1)/2||c[i][1]!=(r+1)/2-l/2){ t=true; break; }
			j=r;
		}
		puts(t?"NO":"YES");
	}
	return 0;
}
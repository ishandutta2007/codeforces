#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,ll>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e5+5; int a[N],st[20][N],lg[N]; 
vector<int> d[N]; int cnt[N];
void add(int x,int op){
	rep0(i,d[x].size()) cnt[d[x][i]]+=op;
}
int gcd(int x,int y){ return y==0?x:gcd(y,x%y); }
int main(){
	int n,q,V=1e5; scanf("%d%d",&n,&q);
	rep(i,2,V) rep(j,1,V/i) d[i*j].pb(i);
	rep(i,1,n) scanf("%d",&a[i]);
	for (int i=1,j=0;i<=n;++i){
		while (j<n){
			bool t=false;
			rep0(k,d[a[j+1]].size())
				if (cnt[d[a[j+1]][k]]){ t=true; break; }
			if (!t) ++j,add(a[j],1); else break;
		}
		st[0][i]=j; add(a[i],-1);
	}
	rep(i,2,n) lg[i]=lg[i>>1]+1;
	rep(j,1,lg[n])
		rep(i,1,n)
			st[j][i]=st[j-1][i]<n?st[j-1][st[j-1][i]+1]:n;
	while (q--){
		int l,r,s=0; scanf("%d%d",&l,&r);
		per(j,lg[r-l+1],0) if (st[j][l]<r) l=st[j][l]+1,s+=1<<j;
		printf("%d\n",s+1);
	}
	return 0;
}
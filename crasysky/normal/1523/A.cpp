#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<pr>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=1e6+6; int a[N],pre[N],suc[N]; char s[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m; scanf("%d%d%s",&n,&m,s);
		rep(i,1,n) a[i]=s[i-1]-'0';
		bool t=false; rep(i,1,n) t=t||a[i];
		if (!t){
			rep(i,1,n) putchar('0'); putchar('\n'); continue;
		}
		pre[0]=0,suc[n+1]=n+1;
		rep(i,1,n) pre[i]=a[i]?i:pre[i-1];
		per(i,n,1) suc[i]=a[i]?i:suc[i+1];
		rep(i,1,n){
			if (a[i]){ putchar('1'); continue; }
			int l=pre[i],r=suc[i];
			if (l==0) putchar(r-i<=m?'1':'0');
			else if (r==n+1) putchar(i-l<=m?'1':'0');
			else putchar((r-i<=m||i-l<=m)&&r-i!=i-l?'1':'0');
		}
		putchar('\n');
	}
	return 0;
}
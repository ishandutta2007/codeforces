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
const int N=1e5+5; int fa[N],ch[N],st[N]; pr cur[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		int nd=1; int tp1=0; cur[++tp1]=mp(1,0);
		rep(i,1,n){
			int a; scanf("%d",&a);
			while (cur[tp1].se+1!=a) --tp1;
			int u=cur[tp1].fi; ++cur[tp1].se;
			fa[++nd]=u,ch[nd]=a;
			cur[++tp1]=mp(nd,0);
			int tp=0;
			for (int x=nd;x!=1;x=fa[x]) st[++tp]=ch[x];
			printf("%d",st[tp--]);
			while (tp) printf(".%d",st[tp--]);
			putchar('\n');
		}
	}
	return 0;
}
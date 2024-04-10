#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define read(x) scanf("%d",&x)
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
const int N = 344444;
int n,m,len1,len2,v;
int Abs(int x) {return x>0?x:-x;}
int a[N],b[N];
int f(int cnt1, int cnt2, int x) { //cnt1*1; cnt2*(<=v); x
	if (cnt2) {
		return (x+v-1)/v; //(x-1)/v+1;
	}
	return cnt1>=1 ? x : (x==0?0:2e9);
}
int main() {
	read(n); read(m);read(len1);read(len2);read(v);
	rep(i,1,len1) read(a[i]); a[len1+1]=1e9;
	rep(i,1,len2) read(b[i]); b[len2+1]=1e9;
	int q; read(q);
	while (q--) {
		int x1,y1,x2,y2;
		read(x1);read(y1);read(x2);read(y2);
		if (y1>y2) {swap(x1,x2); swap(y1,y2);}
		ll res=2e9;
		int x[]={y1,*(lower_bound(a+1,a+len1+1,y1)-1),*(lower_bound(b+1,b+len2+1,y1)-1)};
		int y[]={y2,*lower_bound(a+1,a+len1+1,y2),*lower_bound(b+1,b+len2+1,y2)};
		rep(A,0,2) rep(B,0,2) if (!A||!B) {
			int px=x[A],py=y[B];
			int cnt1=(*lower_bound(a+1,a+len1+1,px))<=py;
			int cnt2=(*lower_bound(b+1,b+len2+1,px))<=py;
			int x=Abs(x2-x1);
			res=min(res,1LL*f(cnt1,cnt2,x)+2LL*(-y2+py-px+y1));
		} //cnt1*1; cnt2*(<=v); x
		/*if (1LL*cnt2*v<=x) res+=cnt2+x-cnt2*v;
		else res+=(x-1)/v+1;*/
		/*else {
			int k=x/v;
			res+=min(k+x-k*v,(k+1)+Abs(x-(k+1)*v));
		}*/
		/*if (cnt2) res+=(x-1)/v;
		else {
			int tmp=1e9; if (cnt1) tmp=min(tmp,x);
			
			res+=tmp;
		}*/
		
		printf("%lld\n",res+Abs(y2-y1));
	}
	return 0;
}
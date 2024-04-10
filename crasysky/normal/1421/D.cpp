#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
int c[10];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int x,y; scanf("%d%d",&x,&y); swap(x,y);
		rep(i,0,5) scanf("%d",&c[i]);
		if (x<0&&y<0) swap(c[0],c[3]),swap(c[1],c[4]),swap(c[2],c[5]),x=-x,y=-y;
		rep(i,0,5) c[i]=min(c[i],c[(i+5)%6]+c[(i+1)%6]);
		if (x>0&&y>0&&x>=y) printf("%lld\n",(ll)y*c[0]+(ll)(x-y)*c[1]);
		if (x>0&&y>0&&x<y) printf("%lld\n",(ll)x*c[0]+(ll)(y-x)*c[5]);
		if (x>0&&y<0) printf("%lld\n",(ll)x*c[1]+(ll)(-y)*c[2]);
		if (x<0&&y>0) printf("%lld\n",(ll)(-x)*c[4]+(ll)y*c[5]);
		if (y==0&&x>0) printf("%lld\n",(ll)x*c[1]);
		if (y==0&&x<0) printf("%lld\n",(ll)(-x)*c[4]);
		if (x==0&&y>0) printf("%lld\n",(ll)y*c[5]);
		if (x==0&&y<0) printf("%lld\n",(ll)(-y)*c[2]);
		if (x==0&&y==0) puts("0");
	}
	return 0;
}
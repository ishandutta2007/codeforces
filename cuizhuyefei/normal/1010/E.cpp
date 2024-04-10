#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define MID ((L+R)>>1)
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 204000,M=18000000;//M!!!!!!!!!!
int X,Y,Z,n,m,k,mx;
int xl,xr,yl,yr,zl,zr,ans[N];
struct dot{
	int x,y,z;
}a[N/2],b[N/2],c[N/2];
bool In(dot a){
	return a.x>=xl&&a.x<=xr&&a.y>=yl&&a.y<=yr&&a.z>=zl&&a.z<=zr;
}
struct juxing{
	int xl,xr,yl,yr,z,ind;
}d[N];int len;
bool cmp1(juxing a, juxing b){return a.z<b.z;}

struct Seg {
    int size;
    int lc[M],rc[M],sum[M];
    inline void init() {size=mx;}
    inline void add(int k, int x, int L, int R) {
        sum[k]++;
        if (L==R) return;
        if (x<=MID) {if (!lc[k]) lc[k]=++size; add(lc[k],x,L,MID);}
        else {if (!rc[k]) rc[k]=++size; add(rc[k],x,MID+1,R);}
    }
    inline int query(int k, int l, int r, int L, int R) {
        if (!k) return 0;
        if (l==L && r==R) return sum[k];
        if (r<=MID) return query(lc[k],l,r,L,MID);
        if (l>=MID+1) return query(rc[k],l,r,MID+1,R);
        return query(lc[k],l,MID,L,MID)+query(rc[k],MID+1,r,MID+1,R);
    }
} tree;
struct Node {
    inline void add(int x, int y) {
    //	printf("add %d %d\n",x,y);
        while (x<=mx) {tree.add(x,y,1,mx); x+=x&-x;}
    }
    inline int query(int x, int l, int r) {
        int res=0;int rec=x;
        while (x) {res+=tree.query(x,l,r,1,mx); x-=x&-x;}
    //	printf("que %d %d %d : %d\n",rec,l,r,res);
        return res;
    }
} BIT;
bool cmp(dot a, dot b){return a.z<b.z;}
int Abs(int x){return x>0?x:-x;}
int sgn(int x){return x>0?1:-1;}
int main() {//freopen("1.in","r",stdin);
	read(X);read(Y);read(Z);mx=max(max(X,Y),Z);
	read(n);read(m);read(k);
	rep(i,1,n)read(a[i].x),read(a[i].y),read(a[i].z);
	rep(i,1,m)read(b[i].x),read(b[i].y),read(b[i].z);
	rep(i,1,k)read(c[i].x),read(c[i].y),read(c[i].z);
	xl=xr=a[1].x;yl=yr=a[1].y;zl=zr=a[1].z;
	rep(i,2,n){
		xl=min(xl,a[i].x);xr=max(xr,a[i].x);
		yl=min(yl,a[i].y);yr=max(yr,a[i].y);
		zl=min(zl,a[i].z);zr=max(zr,a[i].z);
	}
	rep(i,1,m)if(In(b[i])){puts("INCORRECT");return 0;}
	puts("CORRECT");
	rep(i,1,k)
		if(In(c[i]))ans[i]=-1;
		else{
			++len;d[len].ind=i;d[len].z=max(zr,c[i].z);
			d[len].xl=min(xl,c[i].x);d[len].xr=max(xr,c[i].x);
			d[len].yl=min(yl,c[i].y);d[len].yr=max(yr,c[i].y);
			++len;d[len].ind=-i;d[len].z=min(zl,c[i].z)-1;
			d[len].xl=min(xl,c[i].x);d[len].xr=max(xr,c[i].x);
			d[len].yl=min(yl,c[i].y);d[len].yr=max(yr,c[i].y);
		//	printf("[%d %d %d %d]\n",d[len].xl,d[len].xr,d[len].yl,d[len].yr);
		}
	tree.init();
	sort(b+1,b+m+1,cmp);sort(d+1,d+len+1,cmp1);
	int p=0;rep(i,1,len){
		while(p+1<=m&&b[p+1].z<=d[i].z){p++;BIT.add(b[p].x,b[p].y);}
		ans[Abs(d[i].ind)]+=sgn(d[i].ind)*(BIT.query(d[i].xr,d[i].yl,d[i].yr)-BIT.query(d[i].xl-1,d[i].yl,d[i].yr));
	}
//	rep(i,1,k)printf("%d\n",ans[i]);
	rep(i,1,k)if(ans[i]==-1)puts("OPEN");
	else if (ans[i]==0)puts("UNKNOWN");
	else puts("CLOSED");
	return 0;
}
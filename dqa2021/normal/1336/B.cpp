#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;
const ll INF=6e18;

int n,m,q,a[100010],b[100010],c[100010];
ll ans;
void init(){ans=INF;}
int getpre(int *a,int n,int x){
	int p=upper_bound(a+1,a+n+1,x)-a-1;
	if (p) return a[p]; return -1;
}
int getsuf(int *a,int n,int x){
	int p=lower_bound(a+1,a+n+1,x)-a;
	if (p<=n) return a[p]; return -1;
}
ll getval(int x,int y){
	return 1LL*(x-y)*(x-y);
}
void checkmin(int *a,int n,int x,int y){
	if (x>y) swap(x,y);
	int l=1,r=n,mid;
	while (l<r){
		mid=l+r+1>>1;
		if (mid==1||getval(a[mid],x)+getval(a[mid],y)<getval(a[mid-1],x)+getval(a[mid-1],y)) l=mid;
		else r=mid-1;
	}
	ans=min(ans,getval(a[l],x)+getval(a[l],y)+getval(x,y));
}
void solve(){
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read();
	for (int i=1;i<=q;i++) c[i]=read();
	sort(a+1,a+n+1); sort(b+1,b+m+1); sort(c+1,c+q+1);
	n=unique(a+1,a+n+1)-a-1,m=unique(b+1,b+m+1)-b-1,q=unique(c+1,c+q+1)-c-1;
	for (int i=1;i<=n;i++){
		int p=getpre(b,m,a[i]);
		if (~p){
			checkmin(c,q,p,a[i]);
		}
		p=getsuf(b,m,a[i]);
		if (~p){
			checkmin(c,q,a[i],p);
		}
		p=getpre(c,q,a[i]);
		if (~p){
			checkmin(b,m,p,a[i]);
		}
		p=getsuf(c,q,a[i]);
		if (~p){
			checkmin(b,m,a[i],p);
		}
	}
	printf("%I64d\n",ans);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}
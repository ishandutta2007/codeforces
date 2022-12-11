#include<cstdio>
#include<algorithm>
#include<cctype>
#include<assert.h>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G

int n,a[500010];
bool vis[500010];
int A[500010],Atot;
int B[500010],Btot;
int L[500010],R[500010];
int pos[500010];
int id[500010],idtot;
#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)
struct Node{
	int tag,mn;
}node[1<<20];
void pushup(int x){
	node[x].mn=min(node[ls].mn,node[rs].mn);
}
void pushdown(int x){
	int &t=node[x].tag;
	if (!t) return;
	node[ls].tag+=t;
	node[ls].mn+=t;
	node[rs].tag+=t;
	node[rs].mn+=t;
	t=0;
}
void build(int x,int l,int r){
	if (l==r) return node[x]=(Node){0,Btot-l+1},void();
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(x); node[x].tag=0;
}
void update(int x,int l,int r,int ql,int qr,int v){
	if (ql<=l&&r<=qr) return node[x].tag+=v,node[x].mn+=v,void();
	pushdown(x);
	if (ql<=mid) update(ls,l,mid,ql,qr,v);
	if (mid<qr) update(rs,mid+1,r,ql,qr,v);
	pushup(x);
}
#undef ls
#undef rs
#undef mid
void init(){
	Atot=Btot=0;
	for (int i=1;i<=n;i++) L[i]=R[i]=pos[i]=0;
}
void solve(){
//	scanf("%*s%*d");  //!!!
//	static int cnt=0;  //!!!
//	printf("Case %d: ",++cnt);  //!!!
	n=read();
	idtot=0; for (int i=1;i<=n;i++) id[i]=0;
	for (int i=1;i<=n;i++) a[i]=read();
	int tot0=0;
	for (int i=1;i<=n;i++) tot0+=a[i]==0;
	if (tot0<=1) return puts("0"),void();
	int l=-1,r=-1;
	for (int i=1;i<=n;i++) if (!a[i]){l=i;break;}
	for (int i=n;i;i--) if (!a[i]){r=i;break;}
	for (int i=l;i<=r;i++) a[i-l+1]=a[i];
	n=r-l+1;
	for (int i=1;i<=n;i++){
		if (!a[i]) continue;
		if (!id[a[i]]) id[a[i]]=++idtot;
		a[i]=id[a[i]];
	}
//	for (int i=1;i<=n;i++) printf("a %d = %d\n",i,a[i]);
	int mid=-1;
	for (int i=1,t=0;i<=n;i++){
		t+=a[i]==0;
		if (t==(tot0>>1)){
			mid=i; break;
		}
	}
	assert(~mid);
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=mid;i;i--){
		if (!a[i]){A[++Atot]=i;continue;}
		if (vis[a[i]]) continue;
		vis[a[i]]=1; L[a[i]]=i;
		A[++Atot]=i;
	}
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=mid+1;i<=n;i++){
		if (!a[i]){B[++Btot]=i;continue;}
		if (vis[a[i]]) continue;
		vis[a[i]]=1; R[a[i]]=i;
		pos[a[i]]=Btot+1;
//		B[++Btot]=i;
	}
//	printf("A: "); for (int i=1;i<=Atot;i++) printf("%d ",A[i]); puts("");
//	printf("B: "); for (int i=1;i<=Btot;i++) printf("%d ",B[i]); puts("");
	build(1,1,Btot+1);
	int ans=tot0>>1,subans=0;
	for (int i=1;i<=n;i++){
		if (R[i]){
			int t=pos[i];
			update(1,1,Btot+1,t+1,Btot+1,1);
		}
	}
	//checkans
	for (int i=1,Ltot=tot0>>1;i<=Atot;i++){
		while (a[A[i]]){
			int x=a[A[i++]];
			subans++;
			if (!R[x]) continue;
			int t=pos[x];
			update(1,1,Btot+1,t+1,Btot+1,-1);
		}
		Ltot--;
		ans=min(ans,Ltot+subans+node[1].mn);
//		printf("checkans %d + %d + %d\n",Ltot,subans,node[1].mn);
	}
	printf("%d\n",ans);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}
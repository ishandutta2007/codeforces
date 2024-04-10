#include<cstdio>
#define ls k<<1
#define rs k<<1|1
#define int unsigned
int read(){
	int a=0;char c=getchar();
	while(c<48||c>57)c=getchar();while(c>47&&c<58)a=a*10+c-48,c=getchar();
	return a;
}
const int N=1e5,A=0x3fffffff;
struct node{int l,r,o;}bt[N*4];
void Build(int l,int r,int k){
	bt[k]=(node){l,r,A};
	if(l==r)return;
	int m=l+r>>1;
	Build(l,m,ls);Build(m+1,r,rs);
}
int Down(int k){bt[ls].o&=bt[k].o;bt[rs].o&=bt[k].o;}
int Set0(int l,int r,int a,int k){
	node&t=bt[k];
	if(t.l>=l&&t.r<=r){t.o&=a;return 0;}
	Down(k);
	int m=t.l+t.r>>1;
	if(l<=m)Set0(l,r,a,ls);if(r>m)Set0(l,r,a,rs);
	t.o=bt[ls].o|bt[rs].o;
}
int Or(int l,int r,int k){
	node&t=bt[k];
	if(t.l>=l&&t.r<=r)return t.o;
	Down(k);
	int m=t.l+t.r>>1,s=0;
	if(l<=m)s|=Or(l,r,ls);if(r>m)s|=Or(l,r,rs);
	return s;
}
int Toa(int*a,int k){
	node&t=bt[k];
	if(t.l==t.r){a[t.l]=t.o;return 0;}
	Down(k);
	Toa(a,ls);Toa(a,rs);
}
int n,m,l[N],r[N],a[N];
signed main(){
	n=read();m=read();
	Build(1,n,1);
	for(int i=0;i<m;i++)l[i]=read(),r[i]=read(),a[i]=A-read(),Set0(l[i],r[i],a[i],1);
	for(int i=0;i<m;i++)if(Or(l[i],r[i],1)!=a[i])return 0*puts("NO");
	puts("YES");
	Toa(a,1);
	printf("%d",A-a[1]);for(int i=2;i<=n;i++)printf(" %d",A-a[i]);
	return 0;
}
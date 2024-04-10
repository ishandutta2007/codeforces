#include<cstdio>
using namespace std;
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f;
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48);
}
const int o=4e5+10,MOD=1e9+7;
int n,m,p[o][6],l,r,x,s[o][6],ans,C[6][6];char opt;
struct segmenttree{int l,r,sum[6],lzy;}nod[o];
void build(int id,int l,int r){
	nod[id].l=l;nod[id].r=r;nod[id].lzy=-1;
	if(l==r){read(nod[id].sum[0]);for(int i=1;i<6;++i) nod[id].sum[i]=nod[id].sum[i-1]*1ll*l%MOD;return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	for(int i=0;i<6;++i) nod[id].sum[i]=(nod[id<<1].sum[i]+nod[(id<<1)|1].sum[i])%MOD;
}
inline void update(int id){for(int i=0;i<6;++i) nod[id].sum[i]=nod[id].lzy*1ll*(s[nod[id].r][i]+MOD-s[nod[id].l-1][i])%MOD;}
inline void pushdown(int id){nod[id<<1].lzy=nod[id].lzy;nod[(id<<1)|1].lzy=nod[id].lzy;update(id<<1);update((id<<1)|1);nod[id].lzy=-1;}
void modify(int id,int l,int r,int x){
	if(nod[id].l==l&&nod[id].r==r){nod[id].lzy=x;update(id);return;}
	if(nod[id].lzy+1) pushdown(id);
	int md=nod[id].l+nod[id].r>>1;
	if(r<=md) modify(id<<1,l,r,x);
	else if(md<l) modify((id<<1)|1,l,r,x);
	else modify(id<<1,l,md,x),modify((id<<1)|1,md+1,r,x);
	for(int i=0;i<6;++i) nod[id].sum[i]=(nod[id<<1].sum[i]+nod[(id<<1)|1].sum[i])%MOD;
}
int query(int id,int l,int r,int x){
	if(nod[id].l==l&&nod[id].r==r) return nod[id].sum[x];
	if(nod[id].lzy+1) pushdown(id);
	int md=nod[id].l+nod[id].r>>1;
	if(r<=md) return query(id<<1,l,r,x);
	else if(md<l) return query((id<<1)|1,l,r,x);
	else return (query(id<<1,l,md,x)+query((id<<1)|1,md+1,r,x))%MOD;
}
int qp(int b,int f){int res=1;for(int i=1;i<=f;++i) res=res*1ll*b%MOD;return res;}
int main(){
	read(n);read(m);
	for(int i=1;i<=n;++i) p[i][0]=1,s[i][0]=i;
	for(int i=1;i<6;++i) for(int j=1;j<=n;++j) s[j][i]=((p[j][i]=p[j][i-1]*1ll*j%MOD)+s[j-1][i])%MOD;
	for(int i=0;i<6;++i) C[i][0]=1;
	for(int i=1;i<6;++i) for(int j=1;j<=i;++j) C[i][j]=C[i-1][j-1]+C[i-1][j];
	build(1,1,n);
	while(m--){
		opt=getchar();read(l);read(r);read(x);
		if(opt=='=') modify(1,l,r,x);
		else{for(int i=ans=0;i<=x;++i) ans=(ans+query(1,l,r,i)*1ll*qp(1-l,x-i)%MOD*C[x][i]+MOD*11ll)%MOD;write(ans);putchar('\n');}
	}
	return 0;
}
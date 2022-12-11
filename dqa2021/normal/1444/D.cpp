#include<cstdio>
#include<algorithm>
#include<cctype>
#include<bitset>
#include<assert.h>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n,m; int S,T;
int f[1010],g[1010];
int a[1010],b[1010],c[1010],d[1010],atot,btot,ctot,dtot;
bitset<1000010> dp[1010];

bool cmp1(const int &x,const int &y){return x<y;}
bool cmp2(const int &x,const int &y){return x>y;}

struct E{
	int x,y;
}X[1010],Y[1010],Z[1010]; int xtot,ytot,ztot;

void init(){
	//...
}
void solve(){
	n=read(); S=0; for (int i=1;i<=n;i++) f[i]=read(),S+=f[i];
	m=read(); T=0; for (int i=1;i<=m;i++) g[i]=read(),T+=g[i];
	
	if (n!=m) return puts("No"),void();
	if ((S&1)||(T&1)) return puts("No"),void();
	S>>=1,T>>=1;
	
	atot=btot=0;
	dp[0].reset(); dp[0].set(0);
	for (int i=1;i<=n;i++){
		dp[i]=dp[i-1]|(dp[i-1]<<f[i]);
	}
	if (!dp[n][S]) return puts("No"),void();
	for (int i=n,j=S;i;i--){
		if (dp[i-1][j]) b[++btot]=f[i];
		else a[++atot]=f[i],j-=f[i];
	}
	
	ctot=dtot=0;
	dp[0].reset(); dp[0].set(0);
	for (int i=1;i<=m;i++){
		dp[i]=dp[i-1]|(dp[i-1]<<g[i]);
	}
	if (!dp[m][T]) return puts("No"),void();
	for (int i=m,j=T;i;i--){
		if (dp[i-1][j]) d[++dtot]=g[i];
		else c[++ctot]=g[i],j-=g[i];
	}
	
	puts("Yes");
	if (atot<btot){
		swap(atot,btot);
		for (int i=1;i<=atot||i<=btot;i++) swap(a[i],b[i]);
	}
	if (ctot>dtot){
		swap(ctot,dtot);
		for (int i=1;i<=ctot||i<=dtot;i++) swap(c[i],d[i]);
	}
	sort(a+1,a+atot+1,cmp1);
	sort(b+1,b+btot+1,cmp2);
	sort(c+1,c+ctot+1,cmp2);
	sort(d+1,d+dtot+1,cmp1);
	
	xtot=ytot=ztot=0;
	X[++xtot]=(E){0,0};
	for (int i=1,x=0,y=0;i<=ctot;i++){
		y+=c[i];
		X[++xtot]=(E){x,y};
		x+=a[i];
		X[++xtot]=(E){x,y};
	}
	Y[++ytot]=(E){0,0};
	for (int i=atot+1,x=0,y=0;i<=n;i++){
		x+=b[i-atot];
		Y[++ytot]=(E){x,y};
		y+=d[i-ctot];
		Y[++ytot]=(E){x,y};
	}
	Z[++ztot]=X[xtot];
	for (int i=ctot+1,x=Z[1].x,y=Z[1].y;i<=atot;i++){
		y-=d[i-ctot];
		Z[++ztot]=(E){x,y};
		x+=a[i];
		Z[++ztot]=(E){x,y};
	}
	for (int i=1;i<xtot;i++) printf("%d %d\n",X[i].x,X[i].y);
	for (int i=1;i<ztot;i++) printf("%d %d\n",Z[i].x,Z[i].y);
	for (int i=ytot;i>=2;i--) printf("%d %d\n",Y[i].x,Y[i].y);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}
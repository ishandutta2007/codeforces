#include<cstdio>
#include<algorithm>
#include<cctype>
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
typedef long long ll;
typedef unsigned uint;
uint rnd(){
	static uint sd=964751236U;
	return sd^=sd>>17,sd^=sd<<9,sd^=sd>>13,sd^=sd<<23;
}
const ll INF=1e9;

int n; ll w[500010];
ll M,B,dir;  //minval base direction
struct Node{
	ll l,r;
	int ls,rs,siz;
}node[600010];
int idtot,rt;
inline void pushup(int x){
	node[x].siz=node[node[x].ls].siz+1+node[node[x].rs].siz;
}
void split1(int o,ll p,int &x,int &y){  //<=p to left
	if (!o) return x=y=0,void();
	if (node[o].l<=p){
		x=o; split1(node[o].rs,p,node[x].rs,y); pushup(x);
	}
	else{
		y=o; split1(node[o].ls,p,x,node[y].ls); pushup(y);
	}
}
void split2(int o,ll p,int &x,int &y){  //>=p to right
	if (!o) return x=y=0,void();
	if (node[o].r>=p){
		y=o; split2(node[o].ls,p,x,node[y].ls); pushup(y);
	}
	else{
		x=o; split2(node[o].rs,p,node[x].rs,y); pushup(x);
	}
}
void split3(int o,int p,int &x,int &y){  //based on siz
	if (!o) return x=y=0,void();
	if (p<=node[node[o].ls].siz){
		y=o; split3(node[o].ls,p,x,node[y].ls); pushup(y);
	}
	else{
		x=o; split3(node[o].rs,p-node[node[o].ls].siz-1,node[x].rs,y); pushup(x);
	}
}
int merge(int x,int y){
	if (!x||!y) return x|y;
	if (rnd()%(node[x].siz+node[y].siz)<node[x].siz){
		node[x].rs=merge(node[x].rs,y);
		pushup(x); return x;
	}
	else{
		node[y].ls=merge(x,node[y].ls);
		pushup(y); return y;
	}
}


void init(){
//	...
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++) w[i]=read();
	M=0,B=0,dir=1;
	node[idtot=rt=1]=(Node){INF,INF,0,0,1};
	for (int i=1;i<=n;i++){
		if (dir==1){
			int x,y,z;
			split1(rt,B+w[i]-1,x,z);
			if (!x) rt=x;
			else{
				split3(x,node[x].siz-1,x,y);
				node[y].r=min(node[y].r,B+w[i]-1);
				rt=merge(x,y);
			}
		}
		else{
			int x,y,z;
			split2(rt,B-w[i]+1,x,z);
			if (!z) rt=z;
			else{
				split3(z,1,y,z);
				node[y].l=max(node[y].l,B-w[i]+1);
				rt=merge(y,z);
			}
		}
		if (!rt){
			M++;
			B=0,dir=1;
			node[idtot=rt=1]=(Node){1,w[i]-1,0,0,1};
		}
		if (dir==1) B=B+w[i],dir=-1;
		else B=B-w[i],dir=1;
		M++;
		if (w[i]&1) continue;
		ll T=w[i]>>1;
		if (dir==1){
			int x,y,z;
			split1(rt,B+T,x,z);
			bool flg=1;
			if (x){
				split3(x,node[x].siz-1,x,y);
				if (node[y].r>=B+T){
					M--;
					B=0,dir=1;
					node[idtot=rt=1]=(Node){T,T,0,0,1};
				}
				else flg=0,x=merge(x,y);
			}
			else flg=0;
			if (!flg){
				node[y=++idtot]=(Node){B+T,B+T,0,0,1};
				rt=merge(x,merge(y,z));
			}
		}
		else{
			int x,y,z;
			split2(rt,B-T,x,z);
			bool flg=1;
			if (z){
				split3(z,1,y,z);
				if (node[y].l<=B-T){
					M--;
					B=0,dir=1;
					node[idtot=rt=1]=(Node){T,T,0,0,1};
				}
				else flg=0,z=merge(y,z);
			}
			else flg=0;
			if (!flg){
				node[y=++idtot]=(Node){B-T,B-T,0,0,1};
				rt=merge(x,merge(y,z));
			}
		}
	}
	printf("%lld\n",M);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}
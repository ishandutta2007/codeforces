#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 433333;
int n,fa[N],val[N];map<int,int>Map;int q;
int find(int x){
	if(fa[x]==x)return x;int Fa=fa[x];
	fa[x]=find(fa[x]);val[x]^=val[Fa];return fa[x];
}
int main() {
	int lstans=0;
	rep(i,1,N-1)fa[i]=i;
	read(q);while(q--){
		int op;read(op);
		if(op==1){
			int l,r,c;read(l);read(r);read(c);
			l^=lstans;r^=lstans;c^=lstans;
			if(l>r)swap(l,r);l--;
			if(!Map[l])Map[l]=++n;l=Map[l];
			if(!Map[r])Map[r]=++n;r=Map[r];
			int x=find(l),y=find(r);
			if(x!=y){
				fa[x]=y;val[x]=c^val[l]^val[r];
			}
		}
		else{
			int l,r;read(l);read(r);l^=lstans;r^=lstans;
			if(l>r)swap(l,r);l--;
			if(!Map[l])Map[l]=++n;l=Map[l];
			if(!Map[r])Map[r]=++n;r=Map[r];
			int x=find(l),y=find(r);
			if(x!=y)printf("-1\n"),lstans=1;
			else{
				printf("%d\n",lstans=val[l]^val[r]);
			}
		}
	}
	return 0;
}
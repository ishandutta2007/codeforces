#include <bits/stdc++.h>
using namespace std;
const int MAXN=600010;
int n,m,k,op,tot,x,y,mx[MAXN],val[MAXN],sum[MAXN],siz[MAXN],ch[MAXN][2],f[MAXN],rev[MAXN];
int px[MAXN],py[MAXN];
queue <int> q;
void upd (int p) {
	mx[p]=p;
	if (val[mx[ch[p][0]]]>val[mx[p]]) {mx[p]=mx[ch[p][0]];}
	if (val[mx[ch[p][1]]]>val[mx[p]]) {mx[p]=mx[ch[p][1]];}
	sum[p]=sum[ch[p][0]]+sum[ch[p][1]]+1+siz[p];
	return;
}
void pd (int p) {
	if (rev[p]) {
		rev[ch[p][0]]^=1,rev[ch[p][1]]^=1,rev[p]=0;
		swap(ch[ch[p][0]][0],ch[ch[p][0]][1]),swap(ch[ch[p][1]][0],ch[ch[p][1]][1]);
	}
}
int chk (int x) {return (ch[f[x]][0]==x?0:(ch[f[x]][1]==x?1:-1));}
void rot (int x) {
	int y=f[x],z=f[y],k=chk(x),w=ch[x][k^1];
	if (chk(y)>=0) {ch[z][chk(y)]=x;}
	f[x]=z;
	ch[x][k^1]=y,f[y]=x;
	ch[y][k]=w;
	if (w) {f[w]=y;}
	upd(y),upd(x);
	return;
}
void ps (int x) {
	if (chk(x)>=0) {ps(f[x]);}
	pd(x);
}
void splay (int x) {
	ps(x);
	while (chk(x)>=0) {
		int y=f[x];
		if (chk(y)>=0) {
			if (chk(x)==chk(y)) {rot(y);}
			else {rot(x);}
		}
		rot(x);
	}
	return;
}
void access (int x) {
	for (int y=0;x;y=x,x=f[x]) {
		splay(x);
		siz[x]+=sum[ch[x][1]]-sum[y];
		ch[x][1]=y;
		upd(x);
	}
	return;
}
int findr (int x) {
	access(x);
	splay(x);
	while (ch[x][0]) {
		pd(x);
		x=ch[x][0];
	}
	splay(x);
	return x;
}
void maker (int x) {
	access(x);
	splay(x);
	rev[x]^=1;
	swap(ch[x][0],ch[x][1]);
}
void split (int x,int y) {
	maker(x);
	access(y);
	splay(y);
}
void lik (int x,int y) {
	//cout << "            link: " << x << "  " << y << endl;
	maker(x),maker(y);
	if (findr(x)==y) {return;}
	f[y]=x;
	siz[x]+=sum[y];
	return;
}
void ct (int x,int y) {
	//cout << "            cut: " << x << "  " << y << endl;
	split(x,y);
	if (ch[y][0]!=x||ch[x][1]) {return;}
	ch[y][0]=f[x]=0;
	upd(y);
	return;
}
int query (int x,int y) {
	split(x,y);
	return mx[y];
}
void linkt (int x) {
	//cout << "             linkt: " << px[x] << "  " << py[x] << endl;
	int a=findr(px[x]),b=findr(py[x]);
	if (a==b) {
		int w=query(px[x],py[x]);
		if (val[w]>val[x]) {
			ct(px[w],w),ct(py[w],w);
			lik(px[x],x),lik(py[x],x); 
		}
	} else {
		lik(px[x],x),lik(py[x],x);
	} 
}
int main () {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) {mx[i]=i;}
	int daycnt=1;
	tot=n;
	for (int i=1;i<=m;i++) {
		scanf("%d",&op);
		if (op==1) {
			scanf("%d%d",&x,&y);
			++tot;
			mx[tot]=tot,val[tot]=1e6-daycnt,px[tot]=x,py[tot]=y;
			linkt(tot);
			q.push(tot);
		} else if (op==2) {
			scanf("%d",&x);
			maker(x);
			printf("%d\n",(sum[x]+1)/2);
		} else {
			daycnt++;
			while (!q.empty()&&daycnt-(1e6-val[q.front()])>=k) {
				int t=q.front();
				q.pop();
				int a=findr(px[t]),b=findr(py[t]);
				if (a==b) {
					ct(t,px[t]),ct(t,py[t]);
				}
			}
		}
	}
	return 0;
}
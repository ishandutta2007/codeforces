#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
struct node{
	int l,r,m,ls,rs;
	bool ful;
	node(){l=r=m=ls=rs=0;ful=0;}
}t[5000010];
int P,Q,w,L,R,O,h[500010],tot,n,m,p[500010],rt[500010],r[500010],ts,tmp[500010];
bool cmp(int x,int y){
	return (h[x]>h[y]);
}
node merge(node A,node B){
	node C;
	C.l=A.l;
	if (A.ful) C.l+=B.l;
	C.r=B.r;
	if (B.ful) C.r+=A.r;
	C.m=max(A.m,B.m);
	C.m=max(C.m,A.r+B.l);
	C.ful=A.ful&B.ful;
	return C;
}
void upd(int l,int r,int rt1,int rt2,int x){
	if (l==r){
		t[rt2].ful=1;
		t[rt2].l=t[rt2].r=t[rt2].m=1;
		return;
	}
	int m=l+r>>1;
	int ls=t[rt1].ls,rs=t[rt1].rs;
	if (x<=m) upd(l,m,t[rt1].ls,ls=++tot,x);
	else upd(m+1,r,t[rt1].rs,rs=++tot,x);
	t[rt2]=merge(t[ls],t[rs]);
	t[rt2].ls=ls;
	t[rt2].rs=rs;
}
node que(int l,int r,int rt,int L,int R){
	if (l>=L && r<=R) return t[rt];
	int m=l+r>>1;
	node te;
	te.ful=1;
	if (L<=m) te=merge(te,que(l,m,t[rt].ls,L,R));
	if (R>m) te=merge(te,que(m+1,r,t[rt].rs,L,R));
	return te;
}
int main(){
	scanf("%d",&n);
	FOR(i,1,n) getint(h[i]),tmp[++ts]=h[i];
	sort(tmp+1,tmp+ts+1);
	ts=unique(tmp+1,tmp+ts+1)-tmp-1;
	FOR(i,1,n) p[i]=i;
	sort(p+1,p+n+1,cmp);
	rt[0]=0;
	FOR(i,1,n){
		int x=p[i];
		h[x]=lower_bound(tmp+1,tmp+ts+1,h[x])-tmp;
		upd(1,n,rt[i-1],rt[i]=++tot,x);
		r[h[x]]=i;
	}
	scanf("%d",&m);
	FOR(i,1,m){
		getint(P),getint(Q),getint(w);
		int L=1,R=ts;
		while (L<R){
			O=(L+R>>1)+1;
			node T=que(1,n,rt[r[O]],P,Q);
			if (T.m>=w) L=O;
			else R=O-1;
		}
		printf("%d\n",tmp[R]);
	}
	return 0;
}
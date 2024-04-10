// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

template <typename T> void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(int x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}

// ---------- IO ---------- //

const int N=1e9+5;
int n,m,awa;

struct range{
	int l,r;mutable int v;
	range(int L,int R=-1,int V=0):l(L),r(R),v(V){}
	bool operator < (range x) const{return l<x.l;}
};

struct Old_Driver_Tree{
	set<range> qaq;
	#define IT set<range>::iterator
	vector<pair<int,int> > qwq;
	inline IT split(int pos){  //   pos  
		IT tmp=qaq.lower_bound(range(pos));
		if(tmp!=qaq.end()&&tmp->l==pos) return tmp;
		--tmp;int l=tmp->l,r=tmp->r;ll v=tmp->v;
		qaq.erase(tmp);qaq.insert(range(l,pos-1,v));
		return qaq.insert(range(pos,r,v)).first;
	}
	inline void assign(int l,int r,int v){  //  
		IT R=split(r+1),L=split(l),cL;cL=L;
		while(L!=R) awa-=L->v*(L->r-L->l+1),++L;
		qaq.erase(cL,R);qaq.insert(range(l,r,v));awa+=v*(r-l+1);
	}
}ODT;

// ---------- ODT ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);rd(m);awa=n;
	ODT.qaq.insert(range(1,n,1));ODT.qaq.insert(range(n+1,n+1,0));
	int op,l,r;
	for(re i=1;i<=m;i++){
		rd(l);rd(r);rd(op);
		if(op==1) ODT.assign(l,r,0);
		else ODT.assign(l,r,1);
		wr(awa);puts("");
	}
	return 0;
}

// ---------- Main ---------- //
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=(1<<19)+5,lim=2e5;
int mn[N],tag[N],L[N],R[N],A[N],sum[N];
multiset<int> T[N],s[N];
int a[N],n,Q;

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)

void app(int o,int x){
	mn[o]+=x,tag[o]+=x;
}

void down(int o){
	if(tag[o]){
		app(lc,tag[o]);
		app(rc,tag[o]);
		tag[o]=0;
	}
}

void up(int o){
	mn[o]=min(mn[lc],mn[rc]);
	int mx=(SZ(T[o])?*(--T[o].end()):0);
	A[o]=max(mx,max(A[lc],A[rc]));
	if(mn[lc]==mn[rc]){
		sum[o]=sum[lc]+sum[rc];
		sum[o]+=max(mx,max(R[lc],L[rc]));
		L[o]=L[lc],R[o]=R[rc];
	}
	else if(mn[lc]<mn[rc]){
		sum[o]=sum[lc];
		L[o]=L[lc];
		R[o]=max(R[lc],max(mx,A[rc]));
	}
	else{
		sum[o]=sum[rc];
		R[o]=R[rc];
		L[o]=max(L[rc],max(mx,A[lc]));
	}
}

void upd(int o,int l,int r,int x,int y,int z){
	if(l==x&&y==r){
		app(o,z);
		return;
	}
	down(o);
	if(x<=mid) upd(lc,l,mid,x,min(y,mid),z);
	if(mid<y) upd(rc,mid+1,r,max(mid+1,x),y,z);
	up(o);
/*
	puts("=======upd=======");
	printf("## o = %d  (l, r) = (%d, %d)\n",o,l,r);
	printf("mn[o] = %d  sum[o] = %d  L[o] = %d  R[o] = %d\n",
		mn[o],sum[o],L[o],R[o]);
*/
}

void ins(int o,int l,int r,int x,int y,int z){
	if(l==r){
		if(z>0) T[o].insert(z);
		else T[o].erase(T[o].find(-z));
		A[o]=L[o]=(SZ(T[o])>=1);
		return;
	}
	down(o);
	if(x<=mid&&y>mid){
		if(z>0) T[o].insert(z);
		else T[o].erase(T[o].find(-z));
	}
	else if(x<=mid) ins(lc,l,mid,x,y,z);
	else ins(rc,mid+1,r,x,y,z);
	up(o);
/*
	puts("=======ins=======");
	printf("## o = %d  (l, r) = (%d, %d)\n",o,l,r);
	printf("mn[o] = %d  sum[o] = %d  L[o] = %d  R[o] = %d\n",
		mn[o],sum[o],L[o],R[o]);
*/
}

#undef lc
#undef rc
#undef mid

void push(int i,int op){
	if(!SZ(s[i])) return;
//	printf("\n\npush %d\n",i);
	int L=*s[i].begin();
	int R=*(--s[i].end());
	if(L<R) upd(1,1,n,L,R-1,op);
	ins(1,1,n,L,R,SZ(s[i])*op);
}

void print(){
	int ans=L[1]+sum[1]+R[1];
	printf("%d\n",n-ans);
}

int main(){
	read(n),read(Q);
	rep(i,1,n){
		read(a[i]);
		s[a[i]].insert(i);
	}
	rep(i,1,lim) push(i,1);
	print();
	rep(i,1,Q){
		int k,x;
		read(k),read(x);
		push(a[k],-1);
		s[a[k]].erase(k);
		push(a[k],1);
		a[k]=x;
		push(a[k],-1);
		s[a[k]].insert(k);
		push(a[k],1);
		print();
	}
	return 0;
}
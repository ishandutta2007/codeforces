#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int M=1e9+1;
int n,T,K,rt,tot;
int f[6000000],s[2][6000000];
int upd(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return i;
	if(!i)i=++tot;
	if(a<=l&&r<=b){
		f[i]+=x;
		return i;
	}
	int md=(l+r)>>1;
	s[0][i]=upd(s[0][i],l,md,a,b,x);
	s[1][i]=upd(s[1][i],md+1,r,a,b,x);
	return i;
}
int qry(int i,int l,int r,int p){
	if(!i||l==r)return f[i];
	int md=(l+r)>>1;
	if(p<=md)return f[i]+qry(s[0][i],l,md,p);
	return f[i]+qry(s[1][i],md+1,r,p);
}
int ask(int t){
	if(t<0)return -1;
	if(t>1e9)return 2e9;
	int tmp=qry(rt,0,1e9,t);
	return t+tmp;
}
int bs1(int t){
	int l=-1,r=1e9+1;
	while(r>l+1){
		int m=(l+r)>>1;
		if(ask(m)>=T)r=m;
		else l=m;
	}
	return r;
}
int bs2(int t){
	int l=-1,r=1e9+1;
	while(r>l+1){
		int m=(l+r)>>1;
		if(ask(m)<=T)l=m;
		else r=m;
	}
	return l;
}
int lst;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&T);
		int L=bs1(T);
		int R=bs2(T);
		if(0<L)rt=upd(rt,0,1e9,0,L-1,1);
		if(R<1e9)rt=upd(rt,0,1e9,R+1,1e9,-1);
		scanf("%d",&K);
		while(K--){
			int t;scanf("%d",&t);
			t=(lst+t)%M;
			printf("%d\n",(lst=ask(t)));
		}
	}
}
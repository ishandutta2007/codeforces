#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int MOD=1e9+9;
int n,K;
pii a[100004];
int L[100004],R[100004],S[100004],F[100004];
int s[2][100004];
int built(int l,int r){
	if(r<l)return 0;
	int md=-1;
	for(int i=l;i<=r;i++)
		if(md<0||a[md].se<a[i].se)
			md=i;
	s[0][md]=built(l,md-1);
	s[1][md]=built(md+1,r);
	int ls=s[0][md],rs=s[1][md];
	L[md]=ls?L[ls]:a[md].fi;
	R[md]=rs?R[rs]:a[md].fi;
	S[md]=S[ls]+S[rs]+(F[ls]|F[rs]);
	F[md]=(F[ls]|F[rs])^1;
	return md;
}
pii qry(int i,int A,int B){
	if(R[i]<A||B<L[i])return {0,0};
	if(A<=L[i]&&R[i]<=B)return {S[i],F[i]};
	pii tl=qry(s[0][i],A,B);
	pii tr=qry(s[1][i],A,B);
	if(a[i].fi<A||B<a[i].fi)return {tl.fi+tr.fi,tl.se|tr.se};
	return {tl.fi+tr.fi+(tl.se|tr.se),(tl.se|tr.se)^1};
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=K;i++)scanf("%d%d",&a[i].fi,&a[i].se);
	int A,B,C,D;scanf("%d%d%d%d",&A,&B,&C,&D);
	for(int i=K+1;i<=n;i++){
		a[i].fi=((ll)a[i-1].fi*A+B)%MOD;
		a[i].se=((ll)a[i-1].se*C+D)%MOD;
	}
	sort(a+1,a+n+1);
	int rt=built(1,n);
	int q;scanf("%d",&q);
	while(q--){
		int L,R;scanf("%d%d",&L,&R);
		printf("%d\n",qry(rt,L,R).fi);
	}
}
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int o=1e6+10;
int n,q,c[o],ans[o],d[o],pos[o];
struct Query{int l,r,id;}Q[o];
inline bool cmp(Query A,Query B){return A.r<B.r;}
inline void ins(int x,int loc){
	for(int i=19;i+1;--i) if(x&(1<<i)){
		if(!d[i]){d[i]=x;pos[i]=loc;return;}
		if(pos[i]<loc) swap(x,d[i]),swap(loc,pos[i]);
		x^=d[i];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&c[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;++i) scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id=i;
	sort(Q+1,Q+1+q,cmp);
	for(int i=1;i<=q;++i){
		for(int j=Q[i].r;j>Q[i-1].r;--j) ins(c[j],j);
		for(int j=19;j+1;--j)
			if(pos[j]>=Q[i].l&&ans[Q[i].id]<(ans[Q[i].id]^d[j])) ans[Q[i].id]^=d[j];
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}
#include<cstdio>
#include<set>
using namespace std;
const int o=2e5+10;
int n,q,ans;set<int> s[o*4];set<int>::iterator iter;
struct bcj{
	int fa[o];
	int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
	inline void init(){for(int i=0;i<=n+1;++i) fa[i]=i;}
}L,R;
void ins(int id,int pos,int val,int l=1,int r=n){
	s[id].insert(val);
	if(l==r) return;
	int md=l+r>>1;
	if(pos<=md) ins(id<<1,pos,val,l,md);
	else ins((id<<1)|1,pos,val,md+1,r);
}
void query(int id,int ql,int qr,int Ql,int Qr,int l=1,int r=n){
	if(ans<2) return;
	if(ql<=l&&r<=qr){
		if((iter=s[id].lower_bound(Ql))!=s[id].end()&&(*iter)<=Qr) ans=1;
		return;
	}
	int md=l+r>>1;
	if(ql<=md) query(id<<1,ql,qr,Ql,Qr,l,md);
	if(md<qr) query((id<<1)|1,ql,qr,Ql,Qr,md+1,r);
}
int main(){
	scanf("%d%d",&n,&q);L.init();R.init();
	for(int opt,l,r,x;q--;){
		scanf("%d",&opt);
		if(!opt){
			scanf("%d%d%d",&l,&r,&x);
			if(x) ins(1,l,r);
			else{
				for(int i=R.fr(l);i<=r;i=R.fr(i)) R.fa[i]=i+1;
				for(int i=L.fr(r);i>=l;i=L.fr(i)) L.fa[i]=i-1;
			}
		}
		else{
			scanf("%d",&x);ans=2;
			if(L.fa[x]^x) ans=0;
			else query(1,L.fr(x-1)+1,x,x,R.fr(x+1)-1);
			printf((ans<2)?ans?"YES\n":"NO\n":"N/A\n");
		}
	}
	return 0;
}
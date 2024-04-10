#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int o=1e5+10;
int n,m,q,a[o],b[o],L[o],mx[o*4],Ans[o],ans;vector<int> vec[o],Vec[o];
void modify(int id,int pos,int val,int l=1,int r=n){
	mx[id]=max(mx[id],val);
	if(l==r) return;
	int md=l+r>>1;
	if(pos<=md) modify(id<<1,pos,val,l,md);
	else modify((id<<1)|1,pos,val,md+1,r);
}
void query(int id,int ql,int qr,int l=1,int r=n){
	if(ans>=mx[id]) return;
	if(ql<=l&&r<=qr){ans=mx[id];return;}
	int md=l+r>>1;
	if(ql<=md) query(id<<1,ql,qr,l,md);
	if(md<qr) query((id<<1)|1,ql,qr,md+1,r);
}
inline bool cmp(int A,int B){return L[A]<L[B];}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i) scanf("%d%d",&a[i],&b[i]);
	scanf("%d",&q);
	for(int i=1,r;i<=q;++i) scanf("%d%d",&L[i],&r),vec[r].push_back(i);
	for(int i=1;i<=m;++i) Vec[b[i]].push_back(a[i]);
	for(int i=1;i<=n;++i){
		for(int j=Vec[i].size();j--;) modify(1,Vec[i][j],i);
		sort(vec[i].begin(),vec[i].end(),cmp);
		for(int j=vec[i].size(),t;j--;modify(1,L[vec[i][j]],Ans[vec[i][j]]=ans))
			for(ans=L[vec[i][j]],t=0;t^ans;query(1,L[vec[i][j]],ans)) t=ans;
	}
	for(int i=1;i<=q;++i) printf("%d\n",Ans[i]);
	return 0;
}
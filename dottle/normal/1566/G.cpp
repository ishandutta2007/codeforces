#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define int long long
using namespace __gnu_pbds;
#define TREE tree<node,null_type,less<node>,rb_tree_tag,tree_order_statistics_node_update>
const int N=200050;
using namespace std;
 
struct node{
	int fr,to,w;
	bool operator <(const node b)const{
		return w!=b.w?w<b.w:fr!=b.fr?fr<b.fr:to<b.to;
	}
	bool operator ==(const node b)const{
		return w==b.w&&fr==b.fr&&to==b.to;
	}
	bool operator ^(node b){
		return fr!=b.fr&&fr!=b.to&&to!=b.to&&to!=b.fr;
	}
}e[N];
TREE E[N],A,E3;
int fl[N],n,m,q;
map<int,int> ln[N];

node gt(TREE&a,int k){
	return *a.find_by_order(k);
}
 
void add(TREE&a,node b){
	a.insert(b);
}
void del(TREE&a,node b){
	TREE::iterator nw=a.lower_bound(b);
	if(nw!=a.end()&&*nw==b)
		a.erase(nw);
}
int id(TREE&a,node b){
	return a.order_of_key(b);
}
void ck3(int k){
	if(fl[k])del(E3,(node){0,0,fl[k]});fl[k]=0;
	if(E[k].size()>=3)fl[k]=gt(E[k],0).w+gt(E[k],1).w+gt(E[k],2).w;
	if(fl[k])add(E3,(node){0,0,fl[k]});
}
void tryadd(node nw){
	if(id(E[nw.fr],nw)<=3&&id(E[nw.to],nw)<=3)
		add(A,nw);
}
void trydel(int k){
	if(E[k].size()>=4)del(A,gt(E[k],3));
}
 
void add(int fr,int to,int w){
	if(fr>to)swap(fr,to);
	node nw=(node){fr,to,w};
	add(E[fr],nw);
	add(E[to],nw);
	tryadd(nw);
	trydel(fr),trydel(to);
	ck3(fr),ck3(to);
	ln[fr][to]=w;
}
 
//void print(int k){
//	cout<<endl;
//	for(int i=0;i<E[k].size();i++)
//		cout<<E[k][i].fr<<' '<<E[k][i].to<<' '<<E[k][i].w<<endl;
//	cout<<endl;
//}
 
void del(int fr,int to){
	if(fr>to)swap(fr,to);
	int w=ln[fr][to];ln[fr][to]=0;
	del(E[fr],(node){fr,to,w});
	del(E[to],(node){fr,to,w});
	if(E[fr].size()>=3)tryadd(gt(E[fr],2));
	if(E[to].size()>=3)
		tryadd(gt(E[to],2));
	del(A,(node){fr,to,w});
	ck3(fr),ck3(to);
}
node X[5],Y[5];
int calc(){
	int ans=1e17+7;
	if(E3.size())ans=min(ans,gt(E3,0).w);
	for(int i=1;i<A.size()&&i<10;i++)
		if(gt(A,0)^gt(A,i)){
			ans=min(ans,gt(A,0).w+gt(A,i).w);
			break;
		}
	node nw=gt(A,0);
	for(int i=0,P=E[nw.fr].size();i<min(P,4ll);i++)
		for(int j=0,Q=E[nw.to].size();j<min(Q,4ll);j++)
			if(gt(E[nw.fr],i)^gt(E[nw.to],j))
				ans=min(ans,gt(E[nw.fr],i).w+gt(E[nw.to],j).w);
	return ans;
}
 
main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
	}
	scanf("%lld",&q);
	printf("%lld\n",calc());
	for(int i=1,x,y,z;i<=q;i++){
		scanf("%lld",&x);
		if(x==0){
			scanf("%lld%lld",&x,&y);
			del(x,y);
		}else{
			scanf("%lld%lld%lld",&x,&y,&z);
			add(x,y,z);
		}
		printf("%lld\n",calc());
	}
}
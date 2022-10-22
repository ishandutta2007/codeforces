/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
mt19937 rng(20060617);
const int QU=100000;
int qu;
struct fhq_treap{
	int sz,root;
	struct node{unsigned key;int lson,rson,sz,v,sum[5];}nd[QU+1];
	#define key(p) nd[p].key
	#define lson(p) nd[p].lson
	#define rson(p) nd[p].rson
	#define sz(p) nd[p].sz
	#define v(p) nd[p].v
	#define sum(p) nd[p].sum
	void init(){nd[sz=root=0]=node({0,0,0,0,0,{0,0,0,0,0}});}
	void sprup(int p){
		sz(p)=sz(lson(p))+1+sz(rson(p));
		for(int i=0;i<5;i++)sum(p)[i]=sum(lson(p))[i]+sum(rson(p))[(((i-sz(lson(p))-1)%5)+5)%5];
		sum(p)[(sz(lson(p))+1)%5]+=v(p);
	}
	pair<int,int> split(int x,int p=-1){~p||(p=root);
		if(!x)return mp(0,p);
		pair<int,int> sp;
		if(x<=sz(lson(p)))return sp=split(x,lson(p)),lson(p)=sp.Y,sprup(p),mp(sp.X,p);
		return sp=split(x-sz(lson(p))-1,rson(p)),rson(p)=sp.X,sprup(p),mp(p,sp.Y);
	}
	int mrg(int p,int q){
		if(!p||!q)return p|q;
		if(key(p)<key(q))return rson(p)=mrg(rson(p),q),sprup(p),p;
		return lson(q)=mrg(p,lson(q)),sprup(q),q;
	}
	int lss(int v,int p=-1){~p||(p=root);
		if(!p)return 0;
		if(v(p)<v)return sz(lson(p))+1+lss(v,rson(p));
		return lss(v,lson(p));
	}
	int nwnd(int v){return nd[++sz]=node({rng(),0,0,1,v,{0,v,0,0,0}}),sz;}
	void add(int v){
		pair<int,int> sp=split(lss(v));
		root=mrg(mrg(sp.X,nwnd(v)),sp.Y);
	}
	void del(int v){
		pair<int,int> sp=split(lss(v)),sp0=split(1,sp.Y);
		root=mrg(sp.X,sp0.Y);
	}
	int _sum(){return sum(root)[3];}
}trp;
signed main(){
	cin>>qu;
	trp.init();
	while(qu--){
		string tp;int x;
		cin>>tp;
		if(tp=="add")cin>>x,trp.add(x);
		else if(tp=="del")cin>>x,trp.del(x);
		else cout<<trp._sum()<<"\n";
	}
	return 0;
}
/*1
6
add 4
add 5
add 1
add 2
add 3
sum
*/
/*2
14
add 1
add 7
add 2
add 5
sum
add 6
add 8
add 9
add 3
add 4
add 10
sum
del 1
sum
*/
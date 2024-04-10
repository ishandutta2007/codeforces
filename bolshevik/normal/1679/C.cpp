#include<cstdio>
using namespace std;
const int o=1e5+10;
inline int lowbit(int x){return x&-x;}
int n,q;
struct FenwickTree{
	int a[o],b[o];
	inline void modify(int pos,int val){for(;pos<=n;pos+=lowbit(pos)) a[pos]+=val;}
	inline void add(int pos){if(!b[pos]++) modify(pos,1);}
	inline void sub(int pos){if(!--b[pos]) modify(pos,-1);}
	inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res+=a[pos];return res;}
}X,Y;
int main(){
	scanf("%d%d",&n,&q);
	for(int opt,X1,Y1,X2,Y2;q--;){
		scanf("%d%d%d",&opt,&X1,&Y1);
		if(opt==1) X.add(X1),Y.add(Y1);
		else if(opt==2) X.sub(X1),Y.sub(Y1);
		else scanf("%d%d",&X2,&Y2),printf((X.query(X2)-X.query(X1-1)==X2-X1+1||Y.query(Y2)-Y.query(Y1-1)==Y2-Y1+1)?"Yes\n":"No\n");
	}
	return 0;
}
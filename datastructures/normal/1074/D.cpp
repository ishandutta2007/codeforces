#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int q,opt,l,r,x,ans;
map<int,int> dsu,val;
int dsu_find(int x){
	if (dsu[x]==0||dsu[x]==x)return x;
	int qwq=dsu[x];
	int awa=dsu_find(dsu[x]);
	dsu[x]=awa,val[x]=(val[qwq]^val[x]);
	return awa;
}
int main(){
	cin>>q;
	while(q--){
		scanf("%d%d%d",&opt,&l,&r);
		if (ans==-1)ans=1;
		l^=ans,r^=ans;
		if (l>r)swap(l,r);
		l++,r++;
		r++;
		if (opt==1){
			scanf("%d",&x);
			x^=ans;
			int qwq=dsu_find(l),awa=dsu_find(r);
			if (qwq==awa)continue;
			dsu[awa]=l;
			val[awa]=(x^val[r]);
		}
		else{
			int qwq=dsu_find(l),awa=dsu_find(r);
			if (qwq!=awa)ans=-1;
			else ans=(val[l]^val[r]);
			printf("%d\n",ans);
		}
	}
	return 0;
}
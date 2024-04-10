#include<bits/stdc++.h>
using namespace std;
int n;
struct ufset{
	int fat[501];
	int ance(int x){return fat[x]==x?x:fat[x]=ance(fat[x]);}
	void merge(int x,int y){fat[ance(x)]=ance(y);}
	int con_no(){int res=0;for(int i=1;i<=n;i++)if(fat[i]==i)res++;return res;}
}pre_ufs[10001],suf_ufs[10002];
ufset operator|(ufset a,ufset b){
	for(int i=1;i<=n;i++)if(b.fat[i]!=i)a.merge(i,b.fat[i]);
	return a;
}
int x[10001],y[10002];
int main(){
	int m,ask_time,i;scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)pre_ufs[0].fat[i]=suf_ufs[m+1].fat[i]=i;
	for(i=1;i<=m;i++)scanf("%d%d",x+i,y+i),
		pre_ufs[i]=pre_ufs[i-1],pre_ufs[i].merge(x[i],y[i]);
	for(i=m;i;i--)
		suf_ufs[i]=suf_ufs[i+1],suf_ufs[i].merge(x[i],y[i]);
	scanf("%d",&ask_time);
	while(ask_time--){
		int l,r;scanf("%d%d",&l,&r);
		printf("%d\n",(pre_ufs[l-1]|suf_ufs[r+1]).con_no());
	}
	return 0;
}
/*1
6 5
1 2
5 4
2 3
3 1
3 6
6
1 3
2 5
1 5
5 5
2 4
3 3
*/
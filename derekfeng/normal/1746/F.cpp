#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B=30;
mt19937 rng(114514);
int vl[600004][30];
ll bit[300004][30],sm[30];
int n,q,N;
vector<int>all;
int op[300004],x[300004],y[300004];
int a[300004],z[300004];
int lb(int x){
	return lower_bound(all.begin(),all.end(),x)-all.begin();
}
void upd(int i,int x,int v){
	for(;i<=n;i+=i&-i)
		for(int j=0;j<B;j++)
			bit[i][j]+=vl[x][j]*v;
}
void qry(int i,int v){
	for(;i;i-=i&-i)
		for(int j=0;j<B;j++)
			sm[j]+=bit[i][j]*v;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),all.push_back(a[i]);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&op[i],&x[i],&y[i]);
		if(op[i]==2)scanf("%d",&z[i]);
		else all.push_back(y[i]);
	}
	sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=0;i<all.size();i++)for(int j=0;j<B;j++)vl[i][j]=rng();
	for(int i=1;i<=n;i++)a[i]=lb(a[i]),upd(i,a[i],1);
	for(int i=1;i<=q;i++){
		if(op[i]==1){
			upd(x[i],a[x[i]],-1);
			a[x[i]]=lb(y[i]);
			upd(x[i],a[x[i]],1);
		}else{
			memset(sm,0,240);bool ok=1;
			qry(y[i],1),qry(x[i]-1,-1);
			for(int j=0;j<30;j++)ok&=sm[j]%z[i]==0;
			puts(ok?"YES":"NO");
		}
	}
}
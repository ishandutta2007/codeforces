#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+5,S=2e7+5;
int n,lim,a[N],Root[N],ls[S],rs[S],t[S],tot;LL ans;
void change(int rt,int l,int r,int x){
	t[rt]++;if(l==r)return;
	int mid=(l+r)>>1;
	(x<=mid)?change(!ls[rt]?ls[rt]=++tot:ls[rt],l,mid,x):change(!rs[rt]?rs[rt]=++tot:rs[rt],mid+1,r,x);
}
int ask(int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R)return t[rt];
	int mid=(l+r)>>1,res=0;
	if(L<=mid&&ls[rt])res+=ask(ls[rt],l,mid,L,R);
	if(R>mid&&rs[rt])res+=ask(rs[rt],mid+1,r,L,R);
	return res;
}
int main(){
	scanf("%d",&n);lim=n+1;tot=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=min(a[i],lim),Root[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j;j-=(j&-j))ans+=(LL)ask(Root[j],1,lim,i,lim);
		for(int j=i;j<=lim;j+=(j&-j))change(Root[j],1,lim,a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
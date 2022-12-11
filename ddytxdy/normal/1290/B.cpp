#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
char s[N];int fl[N*4],n,q;
void build(int x,int l,int r){
	if(l==r){fl[x]=1<<(s[l]-'a');return;}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	fl[x]=fl[x<<1]|fl[x<<1|1];
}
int query(int x,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return fl[x];
	int mid=(l+r)>>1,ret=0;
	if(ql<=mid)ret=query(x<<1,l,mid,ql,qr);
	if(qr>mid)ret|=query(x<<1|1,mid+1,r,ql,qr);
	return ret;
}
int cnt(int x){int y=0;while(x)y++,x-=x&-x;return y;}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	build(1,1,n);
	scanf("%d",&q);
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		if(l==r||s[l]!=s[r]){puts("Yes");continue;}
		puts(cnt(query(1,1,n,l,r))>2?"Yes":"No");
	}
}
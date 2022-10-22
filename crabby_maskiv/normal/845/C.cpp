#include<bits/stdc++.h>
#define getmx(p) (mx[p]+tag[p])
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
int ls[50*N],rs[50*N],lft[50*N],rgt[50*N],mx[50*N],tag[50*N];
int rt,P;
int build(int l,int r){
	int p=++P;
	lft[p]=l;rgt[p]=r;
	return p;
}
void update(int p){
	mx[p]=max(getmx(ls[p]),getmx(rs[p]));
	return;
}
void pushd(int p){
	if(lft[p]==rgt[p]||!tag[p]) return;
	int mid=(lft[p]+rgt[p])>>1;
	if(!ls[p]) ls[p]=build(lft[p],mid);
	if(!rs[p]) rs[p]=build(mid+1,rgt[p]);
	tag[rs[p]]+=tag[p];tag[ls[p]]+=tag[p];
	mx[p]=getmx(p);
	tag[p]=0;
	return;
}
void change(int p,int l,int r){
	if(lft[p]==l&&rgt[p]==r){
		tag[p]++;
		return;
	}
	pushd(p);
	int mid=(lft[p]+rgt[p])>>1;
	if(l<=mid&&!ls[p]) ls[p]=build(lft[p],mid);
	if(r>mid&&!rs[p]) rs[p]=build(mid+1,rgt[p]);
	if(r<=mid) change(ls[p],l,r);
	else if(l>mid) change(rs[p],l,r);
	else{
		change(ls[p],l,mid);
		change(rs[p],mid+1,r);
	}
	update(p);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	rt=build(0,1000000000);
	for(i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		change(rt,x,y);
	}
	cout<<(getmx(rt)>2?"NO":"YES");
	return 0;
}
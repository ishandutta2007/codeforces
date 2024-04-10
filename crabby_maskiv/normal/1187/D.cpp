#include<bits/stdc++.h>
#define getmn(p) (s[p].tag?s[p].tag:s[p].num)
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
vector<int> v[N];
int cnt[N];
int a[N],b[N],c[N];
struct sgt{
	int ls,rs,l,r,num,tag;
};
sgt s[3*N];
int rt,P;
void update(int p){
	s[p].num=min(getmn(s[p].ls),getmn(s[p].rs));
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	s[p].ls=s[p].rs=s[p].tag=0;
	s[p].num=inf;
	if(l==r) return p;
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	return p;
}
void pushd(int p){
	if(!s[p].tag) return;
	s[s[p].ls].tag=s[s[p].rs].tag=s[p].tag;
	s[p].num=s[p].tag;
	s[p].tag=0;
}
void change(int p,int l,int r,int x){
	if(s[p].l==l&&s[p].r==r){
		s[p].tag=x;
		return;
	}
	pushd(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) change(s[p].ls,l,r,x);
	else if(l>mid) change(s[p].rs,l,r,x);
	else{
		change(s[p].ls,l,mid,x);
		change(s[p].rs,mid+1,r,x);
	}
	update(p);
}
int query(int p,int l,int r){
	if(l>r) return inf;
	if(s[p].l==l&&s[p].r==r)
		return getmn(p);
	pushd(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) return query(s[p].ls,l,r);
	else if(l>mid) return query(s[p].rs,l,r);
	else return min(query(s[p].ls,l,mid),query(s[p].rs,mid+1,r));
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;
	cin>>T;
	c[0]=inf;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) cin>>b[i];
		for(i=1;i<=n;i++){
			v[a[i]].clear();
			cnt[a[i]]=0;
		}
		for(i=1;i<=n;i++) v[b[i]].push_back(i);
		P=0;
		rt=build(1,n);
		for(i=1;i<=n;i++){
			if(cnt[a[i]]>=v[a[i]].size()){
				cout<<"NO"<<endl;
				break;
			}
			c[i]=v[a[i]][cnt[a[i]]++];
		}
		if(i<=n) continue;
		for(i=1;i<=n;i++){
			if(query(rt,c[i]+1,n)<a[i]){
				cout<<"NO"<<endl;
				break;
			}
			change(rt,c[i],c[i],a[i]);
		}
		if(i>n) cout<<"YES"<<endl;
	}
	return 0;
}
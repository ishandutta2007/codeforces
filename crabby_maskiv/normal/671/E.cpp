#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll w[N],g[N],a[N],b[N];
int stk[N],top;
struct sgt{
	int l,r,ls,rs;
	ll tag,add,mx0,mn1,mx1;
	//mx0:max(b)
	//mn1:min(max(b')-b)
	//mx1:max(b')
}s[3*N];
int rt,P;
inline void pushd(int p){
	if(s[p].tag==0) return;
	s[p].mx1+=s[p].tag;
	s[p].mn1+=s[p].tag;
	if(s[p].ls) s[s[p].ls].tag+=s[p].tag;
	if(s[p].rs) s[s[p].rs].tag+=s[p].tag;
	s[p].tag=0;
}
ll get(int p,ll x){
	pushd(p);
	if(s[p].l==s[p].r)
		return x-s[p].mx0;
	pushd(s[p].ls);pushd(s[p].rs);
	if(s[s[p].ls].mx1<=x)
		return min(x-s[s[p].ls].mx0,get(s[p].rs,x));
	else return min(get(s[p].ls,x),s[s[p].rs].mn1);
}
inline void upd(int p){
	s[p].mn1=min(s[s[p].ls].mn1,get(s[p].rs,s[s[p].ls].mx1));
	s[p].mx0=max(s[s[p].ls].mx0,s[s[p].rs].mx0);
	s[p].mx1=max(s[s[p].ls].mx1,s[s[p].rs].mx1);
	s[p].add=s[s[p].ls].add+s[s[p].rs].add;
}
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	if(l==r){
		s[p].mx0=s[p].mx1=b[l];
		s[p].mn1=inf;
		return p;
	}
	int mid=s[p].l+s[p].r>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
void chg0(int p,int pos,ll x){
	pushd(p);
	if(s[p].l==s[p].r){
		s[p].add+=x;
		return;
	}
	int mid=s[p].l+s[p].r>>1;
	if(pos<=mid){
		chg0(s[p].ls,pos,x);
		pushd(s[p].rs);
	}
	else{
		chg0(s[p].rs,pos,x);
		pushd(s[p].ls);
	}
	upd(p);
}
void chg1(int p,int pos,ll x){
	if(s[p].l==s[p].r){
		s[p].tag+=x;
		pushd(p);
		return;
	}
	pushd(p);
	int mid=s[p].l+s[p].r>>1;
	if(pos<=mid){
		chg1(s[p].ls,pos,x);
		s[s[p].rs].tag+=x;
		pushd(s[p].rs);
	}
	else{
		chg1(s[p].rs,pos,x);
		pushd(s[p].ls);
	}
	upd(p);
}
int qry0(int p,ll x){
	if(s[p].l==s[p].r)
		return s[p].l-(s[p].add>x);
	if(s[s[p].ls].add<=x) return qry0(s[p].rs,x-s[s[p].ls].add);
	else return qry0(s[p].ls,x);
}
vector<int> c;
void qry1(int p,int l,int r){
	pushd(p);
	if(s[p].l==l&&s[p].r==r){
		c.push_back(p);
		return;
	}
	int mid=s[p].l+s[p].r>>1;
	if(r<=mid) qry1(s[p].ls,l,r);
	else if(l>mid) qry1(s[p].rs,l,r);
	else{
		qry1(s[p].ls,l,mid);
		qry1(s[p].rs,mid+1,r);
	}
}
int qry2(int p,ll x){
	pushd(p);
	if(s[p].l==s[p].r){
		if(x-s[p].mx0<=m) return s[p].l;
		else return -1;
	}
	pushd(s[p].ls);pushd(s[p].rs);
	if(get(s[p].rs,max(x,s[s[p].ls].mx1))<=m)
		return qry2(s[p].rs,max(x,s[s[p].ls].mx1));
	else return qry2(s[p].ls,x);
}
int qry3(int id,ll x){
	if(id==c.size()-1){
		if(get(c[id],x)<=m) return qry2(c[id],x);
		else return -1;
	}
	int res=qry3(id+1,max(x,s[c[id]].mx1));
	if(res!=-1) return res;
	if(get(c[id],x)<=m) return qry2(c[id],x);
	return -1;
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<n;i++) cin>>w[i];
	for(i=1;i<=n;i++) cin>>g[i];
	for(i=1;i<n;i++) a[i]=a[i-1]-w[i]+g[i];
	for(i=1;i<n;i++) b[i]=b[i-1]-w[i]+g[i+1];
	rt=build(0,n-1);
	int ans=1;
	stk[++top]=n-1;
	for(i=n-1;i;i--){
		while(top&&a[i-1]<=a[stk[top]]){
			if(top>1){
				ll x=a[stk[top]]-a[stk[top-1]];
				chg0(rt,stk[top-1],-x);
				chg1(rt,stk[top-1]-1,-x);
			}
			top--;
		}
		if(top){
			ll x=a[i-1]-a[stk[top]];
			chg0(rt,stk[top],x);
			chg1(rt,stk[top]-1,x);
		}
		stk[++top]=i-1;
		int r=qry0(rt,m);//lim : add[l,r]<=m
		if(r<i) continue;
		//maxb'[l-1,r-1]<=b[r]+m
		ll pre=b[i-1];
		if(top>1&&stk[top-1]==i) pre+=a[i-1]-a[stk[top-1]];
		c.clear();
		qry1(rt,i,r);
		int t=qry3(0,pre);
		ans=max(ans,t-i+2);
	}
	cout<<ans;
	return 0;
}
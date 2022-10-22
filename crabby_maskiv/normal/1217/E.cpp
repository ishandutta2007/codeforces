#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=1000000007ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
struct node{
	int l,r,ls,rs;
	ll mn0[10],mn1[10];
};
node s[N*3];
int rt,P;
void upd(int p){
	for(int i=1;i<10;i++){
		if(s[s[p].ls].mn0[i]<s[s[p].rs].mn0[i]){
			s[p].mn0[i]=s[s[p].ls].mn0[i];
			s[p].mn1[i]=min(s[s[p].rs].mn0[i],s[s[p].ls].mn1[i]);
		}
		else{
			s[p].mn0[i]=s[s[p].rs].mn0[i];
			s[p].mn1[i]=min(s[s[p].ls].mn0[i],s[s[p].rs].mn1[i]);
		}		
	}
}
ll c[10];
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	if(l==r){
		for(int i=1;i<10;i++) 
			s[p].mn0[i]=s[p].mn1[i]=inf;
		return p;
	}
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	upd(p);
	return p;
}
void chg(int p,int pos){
	if(s[p].l==s[p].r){
		for(int i=1;i<10;i++) s[p].mn0[i]=c[i];
		return;
	}
	int mid=(s[p].l+s[p].r)>>1;
	if(pos<=mid) chg(s[p].ls,pos);
	else chg(s[p].rs,pos);
	upd(p);
}
pair<ll,ll> query(int p,int pos,int l,int r){
	if(s[p].l==l&&s[p].r==r)
		return {s[p].mn0[pos],s[p].mn1[pos]};
	int mid=(s[p].l+s[p].r)>>1;
	if(r<=mid) return query(s[p].ls,pos,l,r);
	else if(l>mid) return query(s[p].rs,pos,l,r);
	else{
		pair<ll,ll> q1=query(s[p].ls,pos,l,mid),q2=query(s[p].rs,pos,mid+1,r);
		if(q1.first<q2.first) return {q1.first,min(q1.second,q2.first)};
		else return {q2.first,min(q2.second,q1.first)};
	}
}
int main() {
	int i,j;
	scanf("%d%d",&n,&m);
	rt=build(1,n);
	for(i=1;i<=n;i++){
		ll x;scanf("%lld",&x);
		ll k=x;
		for(j=1;j<10;j++){
			if(k%10) c[j]=x;
			else c[j]=inf;
			k/=10;
		}
		chg(rt,i);
	}
	while(m--){
		int op;ll x,y;
		scanf("%d%lld%lld",&op,&x,&y);
		if(op==1){
			ll k=y;
			for(j=1;j<10;j++){
				if(k%10) c[j]=y;
				else c[j]=inf;
				k/=10;
			}
			chg(rt,x);
		}
		else{
			ll ans=inf;
			for(i=1;i<10;i++){
				pair<ll,ll> q=query(rt,i,x,y);
				ans=min(ans,q.first+q.second);				
			}
			if(ans==inf) printf("-1\n");
			else printf("%lld\n",ans);
		}
	}
    return 0;
}
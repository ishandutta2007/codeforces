#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50,M=2e6+20,P=1e5;
int n,q,s[N],m[N],r[N],rt[N],cnt,lc[M],rc[M];
struct node{LL s1,s2;node operator +(const node &b){return (node){s1+b.s1,s2+b.s2};}}t[M];
int read(){
	int x=0,c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
map<int,int>mp;
map<int,int>::iterator it,jt;
void split(int x){
	if(mp.count(x))return;
	it=--mp.upper_bound(x);
	mp[x]=it->second;
}
void change(int &x,int y,int l,int r,int p,node d){
	x=++cnt;t[x]=t[y]+d;lc[x]=lc[y];rc[x]=rc[y];
	if(l==r)return;int mid=(l+r)>>1;
	if(p<=mid)change(lc[x],lc[y],l,mid,p,d);
	else change(rc[x],rc[y],mid+1,r,p,d);
}
node query(int x,int l,int r,int ql,int qr){
	if(ql>qr)return t[0];
	if(l>=ql&&r<=qr||!x)return t[x];
	int mid=(l+r)>>1;
	if(qr<=mid)return query(lc[x],l,mid,ql,qr);
	if(ql>mid)return query(rc[x],mid+1,r,ql,qr);
	return query(lc[x],l,mid,ql,qr)+query(rc[x],mid+1,r,ql,qr);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		s[i]=read(),m[i]=read(),r[i]=read();
		rt[i]=rt[i-1];
		if(r[i])change(rt[i],rt[i],0,P,m[i]/r[i],(node){r[i],m[i]});
	}
	q=read();mp[1]=-1;
	for(int i=1,t,l,r;i<=q;i++){
		t=read();l=read();r=read();
		split(l);split(r+1);LL ret=0;
		for(it=mp.lower_bound(l);it->first<=r;){
			jt=it++;int l=jt->first,r=it->first,tt=jt->second;
			if(~tt){
				int T=min(t-tt,P+1);
				node a=query(rt[l-1],0,P,0,T-1),b=query(rt[r-1],0,P,0,T-1),c=query(rt[l-1],0,P,T,P),d=query(rt[r-1],0,P,T,P);
				ret+=b.s2-a.s2+(d.s1-c.s1)*(t-tt);
			}
			else for(int j=l;j<r;j++)ret+=min(s[j]+1ll*t*::r[j],1ll*m[j]);
			mp.erase(jt);
		}
		mp[l]=t;printf("%lld\n",ret);
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,d,a[200004],bit[200004];
vector<int>all;map<int,int>mp;
ll sm1[524300],sm2[524300];
int cnt[524300],tg[524300];
void push(int i,int x){
	sm2[i]+=(ll)2*sm1[i]*x+(ll)x*x*cnt[i];
	sm1[i]+=(ll)x*cnt[i];
	tg[i]+=x;
}
void pushdown(int i){
	push(i<<1,tg[i]);
	push(i<<1|1,tg[i]);
	tg[i]=0;
}
void pushup(int i){
	sm1[i]=sm1[i<<1]+sm1[i<<1|1];
	sm2[i]=sm2[i<<1]+sm2[i<<1|1];
	cnt[i]=cnt[i<<1]+cnt[i<<1|1];
}
void upd(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){push(i,x);return;}
	int md=(l+r)>>1;
	pushdown(i);
	upd(i<<1,l,md,a,b,x),upd(i<<1|1,md+1,r,a,b,x);
	pushup(i);
}
void alive(int i,int l,int r,int p,int x){
	if(l==r)sm2[i]=(ll)x*x,sm1[i]=x,cnt[i]=1,tg[i]=0;
	else{
		int md=(l+r)>>1;
		pushdown(i);
		if(p<=md)alive(i<<1,l,md,p,x);
		else alive(i<<1|1,md+1,r,p,x);
		pushup(i);
	}
}
void dead(int i,int l,int r,int p){
	if(l==r)sm1[i]=sm2[i]=cnt[i]=tg[i]=0;
	else{
		int md=(l+r)>>1;
		pushdown(i);
		if(p<=md)dead(i<<1,l,md,p);
		else dead(i<<1|1,md+1,r,p);
		pushup(i);
	}
}
int qry(int i,int l,int r,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return cnt[i];
	int md=(l+r)>>1;
	return qry(i<<1,l,md,a,b)+qry(i<<1|1,md+1,r,a,b);
}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),all.push_back(a[i]);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	m=all.size()-1;
	for(int i=1;i<=n;i++){
		int p1=lower_bound(all.begin(),all.end(),a[i])-all.begin();
		int p2=upper_bound(all.begin(),all.end(),a[i]+d)-all.begin()-1;
		if(!mp[a[i]]){
			if(p1<p2)upd(1,0,m,p1+1,p2,1);
			int pos=lower_bound(all.begin(),all.end(),a[i]-d)-all.begin();
			int x=0;
			if(pos<p1)x=qry(1,0,m,pos,p1);
			alive(1,0,m,p1,x),mp[a[i]]=1;
		}else{
			if(p1<p2)upd(1,0,m,p1+1,p2,-1);
			dead(1,0,m,p1),mp[a[i]]=0;
		}
		printf("%lld\n",(sm2[1]-sm1[1])/2);
	}
}
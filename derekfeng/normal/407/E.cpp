#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,K,d,a[200004],L=0,R=-1,cnt,m;
map<int,int>ID,lst;
vector<int>b[200004],v;
stack<pii>sta1,sta2;
int dat[525000],mn[525000],pos;
void init(int i,int l,int r){
	dat[i]=mn[i]=0;
	if(l!=r){
		int md=(l+r)>>1;
		init(i<<1,l,md),init(i<<1|1,md+1,r);
	}
}
void upd(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		dat[i]+=x,mn[i]+=x;
		return;
	}
	int md=(l+r)>>1;
	upd(i<<1,l,md,a,b,x),upd(i<<1|1,md+1,r,a,b,x);
	mn[i]=min(mn[i<<1],mn[i<<1|1])+dat[i];
}
int bs(int i,int l,int r,int tg){
	if(l==r)return l;
	int md=(l+r)>>1;
	tg+=dat[i];
	if(mn[i<<1]+tg<=K)return bs(i<<1,l,md,tg);
	return bs(i<<1|1,md+1,r,tg);
}
int qry(int i,int l,int r,int a,int b,int tg){
	if(r<a||b<l)return n+1;
	if(a<=l&&r<=b){
		if(mn[i]+tg<=K)return bs(i,l,r,tg);
		return n+1;
	}
	int md=(l+r)>>1;
	tg+=dat[i];
	int tmp=qry(i<<1,l,md,a,b,tg);
	if(tmp<n+1)return tmp;
	return qry(i<<1|1,md+1,r,a,b,tg);
}
void sol(){
	while(!sta1.empty())sta1.pop();
	while(!sta2.empty())sta2.pop();
	lst.clear(),m=v.size()-1;
	sta1.push({2e9+1,0}),sta2.push({-2e9-1,0});
	init(1,1,m),pos=1;
	for(int i=1;i<=m;i++){
		int p=v[i];
		pos=max(pos,lst[a[p]]+1),lst[a[p]]=i;
		if(i!=1)upd(1,1,m,1,i-1,-1);
		while(sta1.top().fi<a[p]){
			pii u=sta1.top();sta1.pop();
			upd(1,1,m,sta1.top().se+1,u.se,a[p]-u.fi);
		}
		sta1.push({a[p],i});
		while(sta2.top().fi>a[p]){
			pii u=sta2.top();sta2.pop();
			upd(1,1,m,sta2.top().se+1,u.se,u.fi-a[p]);
		}
		sta2.push({a[p],i});
		int t=qry(1,1,m,pos,i,0);
		int LL=v[1]-1+t,RR=v[1]-1+i;
		if(RR-LL>R-L||(RR-LL==R-L&&LL<L))L=LL,R=RR;
	}
}
void solve(vector<int>&V){
	for(int i=0,j;i<V.size();i=j){
		for(j=i+1;j<V.size()&&V[j]-V[j-1]==1;j++);
		v.clear(),v.push_back(0);
		for(int k=i;k<j;k++)v.push_back(V[k]);
		sol();
	}
}
int main(){
	scanf("%d%d%d",&n,&K,&d);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]+=1e9;
	if(d==0){
		for(int i=1,j;i<=n;i=j){
			for(j=i;j<=n&&a[i]==a[j];j++);
			if(j-i>R-L+1)L=i,R=j-1;
		}
		printf("%d %d",L,R);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int t=a[i]%d;
		if(!ID[t])ID[t]=++cnt;
		b[ID[t]].push_back(i),a[i]=(a[i]-t)/d;
	}
	for(int i=1;i<=cnt;i++)solve(b[i]);
	printf("%d %d",L,R);
}
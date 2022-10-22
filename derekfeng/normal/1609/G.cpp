#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
struct BIT{
	ll bit1[100004],bit2[100004];
	void init(){
		memset(bit1,0,sizeof(bit1));
		memset(bit2,0,sizeof(bit2));
	}
	void add(int id,ll x,ll y){
		for(;id<=m;id+=(id&-id))bit1[id]+=x,bit2[id]+=y;
	}
	void upd(int l,int r,ll x){
		add(l,x,-x*(l-1)),add(r+1,-x,x*r);
	}
	ll ask(int id){
		ll res1=0,res2=0,x=id;
		for(;id;id-=(id&-id))res1+=bit1[id],res2+=bit2[id];
		return res1*x+res2;
	}
	ll qry(int l,int r){
		return ask(r)-ask(l-1);
	}
}tr;
int bit[100004];
ll a[104],b[100004],S;
ll SUM;
ll da[104],db[100004];
void add(int i,int d){
	for(;i<=m;i+=i&-i)bit[i]+=d;
}
void ins(int l,int r,int d){
	add(l,d),add(r+1,-d);
}
int bs(ll x){
	int cur=0,cnt=0;
	for(int i=18;~i;i--){
		if((cur+(1<<i))>m)continue;
		int ncur=cur+(1<<i),ncnt=cnt+bit[ncur];
		if(db[ncur]+ncnt<=x)cur=ncur,cnt=ncnt;
	}
	return cur;
}
ll calc(){
	ll ans=S*(n+m+1)+SUM;
	for(int i=1;i<=n;i++){
		int pos=bs(da[i]);
		ans+=tr.qry(1,pos)+da[i]*(m-pos);
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(int i=1;i<n;i++)da[i]=a[i+1]-a[i];n--;
	for(int i=1;i<m;i++)db[i]=b[i+1]-b[i];m--;
	for(int i=1;i<=n;i++)SUM+=da[i]*(n-i+1);
	for(int i=1;i<=m;i++)SUM+=db[i]*(m-i+1);
	for(int i=1;i<=m;i++)tr.upd(i,i,db[i]);
	S=a[1]+b[1];
	for(int i=1;i<=q;i++){
		int op,k,d;scanf("%d%d%d",&op,&k,&d);
		if(op==1){
			if(k>n)k--,S+=d;
			for(int i=n,j=0;j<k;i--,j++)da[i]+=d;
			SUM+=(ll)d*k*(k+1)/2;
		}else{
			if(k>m)k--,S+=d;
			ins(m-k+1,m,d);
			tr.upd(m-k+1,m,d); 
			SUM+=(ll)d*k*(k+1)/2;
		}
		printf("%lld\n",calc());
	}
}
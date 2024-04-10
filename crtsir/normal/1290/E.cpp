#include<bits/stdc++.h>
using namespace std;
int n,a[150003],_[150003];
struct BIT{
	int dat[150003];
	void init(){
		memset(dat,0,sizeof(dat));
	}
	int query(int x){
		int ret=0;
		while(x){
			ret+=dat[x];
			x^=(x&-x);
		}return ret;
	}
	void add(int x,int y){
		while(x<=n){
			dat[x]+=y;
			x+=(x&-x);
		}
	}
}tr1,tr2;
long long sum;
void add1(int x,int y){
	tr1.add(x,y);
	sum+=1ll*tr2.query(n+1-x)*y;
}
void add2(int x,int y){
	sum+=1ll*tr1.query(x)*y;
	tr2.add(n+1-x,y);
}
struct sgt{
	int mn[524288],mc[524288],sn[524288],lzy[524288];
	void init(){
		sum=0;
		memset(mn,31,sizeof(mn));
		memset(mc,0,sizeof(mc));
		memset(sn,31,sizeof(sn));
		memset(lzy,-1,sizeof(lzy));
	}
	void pushtag(int k,int val,bool tp){
		if(mn[k]>=val)
			return;
		if(tp){
			add1(mn[k],-mc[k]);
			add1(val,mc[k]);
		}
		mn[k]=val;
		lzy[k]=val;
	}
	void pushdown(int k){
		pushtag(k<<1,lzy[k],0);
		pushtag(k<<1|1,lzy[k],0);
		lzy[k]=0; 
	}
	void pushup(int k){
		if(mn[k<<1]<mn[k<<1|1]){
			mn[k]=mn[k<<1];
			mc[k]=mc[k<<1];
			sn[k]=min(sn[k<<1],mn[k<<1|1]);
		}
		if(mn[k<<1]==mn[k<<1|1]){
			mn[k]=mn[k<<1];
			mc[k]=mc[k<<1]+mc[k<<1|1];
			sn[k]=min(sn[k<<1],sn[k<<1|1]);
		}
		if(mn[k<<1]>mn[k<<1|1]){
			mn[k]=mn[k<<1|1];
			mc[k]=mc[k<<1|1];
			sn[k]=min(mn[k<<1],sn[k<<1|1]);
		}
	}
	void add(int k){
		k+=262144;
		int tk=k;vector<int>v;tk>>=1;
		while(tk)v.push_back(tk),tk>>=1;
		while(v.size())pushdown(v.back()),v.pop_back();
		mn[k]=1;mc[k]=1;
		add1(1,1);
		k>>=1;
		while(k){
			pushup(k);
			k>>=1;
		}
	}
	void modify(int l,int r,int _l,int _r,int k,int val){
		if(l>_r||r<_l||val<=mn[k])return;
		if(_l<=l&&r<=_r&&val<sn[k]){
			pushtag(k,val,1);
			return;
		}
		pushdown(k);
		modify(l,l+r>>1,_l,_r,k<<1,val);
		modify(l+r+1>>1,r,_l,_r,k<<1|1,val);
		pushup(k);
	}
}TR;
long long ans[150003];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>_[i],a[_[i]-1]=i+1;
	for(int i=0;i<2;i++){
		tr1.init();tr2.init();TR.init();sum=0;
		for(int j=0;j<n;j++){
			if(a[j]!=n)
				TR.modify(0,262143,a[j]+1,n,1,a[j]+1);
			TR.add(a[j]);
			add2(a[j],1);
			ans[j]+=sum;
			a[j]=n+1-a[j];
		}
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]-1ll*(i+1)*(i+1)<<'\n';
}
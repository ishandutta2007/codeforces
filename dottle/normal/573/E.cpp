#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

struct apl{
	#define ls sn[0][k]
	#define rs sn[1][k]
	int sn[2][N],fa[N];
	int rt;
	int L[N],R[N],sz[N],W[N],dl[N],ad[N];
	apl(){rt=1,sz[1]=1;}
	void pshtg(int k,int d,int a){
		ad[k]+=a,dl[k]+=d;
		L[k]+=d;
		W[k]+=d+a*sz[ls];
		R[k]+=d+a*(sz[k]-1);
	} 
	int isr(int k){return k==sn[1][fa[k]];}
	void pshdn(int k){
		if(dl[k]||ad[k])
			pshtg(ls,dl[k],ad[k]),pshtg(rs,dl[k]+ad[k]*(sz[ls]+1),ad[k]);
		dl[k]=ad[k]=0;
	}
	void pshup(int k){
		sz[k]=sz[ls]+sz[rs]+1;
		L[k]=ls?L[ls]:W[k];
		R[k]=rs?R[rs]:W[k];
	}
	int getpos(int k,int w,int s){
		pshdn(k);
		if(ls&&R[ls]+(s+sz[ls])*w>W[k])return getpos(ls,w,s);
		else if(!rs||W[k]+(s+sz[ls]+1)*w>L[rs]) return s+sz[ls]+1;
		else return getpos(rs,w,s+1+sz[ls]);
	}
	void rot(int x){
		int y=fa[x],z=fa[y],k=isr(x),w=sn[!k][x];
		if(z)sn[isr(y)][z]=x;fa[x]=z;
		sn[!k][x]=y,fa[y]=x;
		sn[k][y]=w;if(w)fa[w]=y;
		pshup(y),pshup(x);
	}
	void spaly(int x,int goal){
		stack<int> s;
		for(int i=x;i;i=fa[i])s.push(i);
		while(s.size())pshdn(s.top()),s.pop();
		while(fa[x]!=goal){
			int y=fa[x],z=fa[fa[x]];
			if(z)rot(isr(x)^isr(y)?x:y);
			rot(x);
		} 
		if(goal==0)rt=x;
	}
	int kth(int x){
		int k=rt;
		while(x&&k){
			pshdn(k); 
			if(x<=sz[ls])k=ls;
			else if(x==sz[ls]+1)break;
			else x-=sz[ls]+1,k=rs;
		}
		spaly(k,0);
		return k;
	}
	int getv(int x){
		int res=0,k=rt;
		while(x&&k){
			pshdn(k); 
			if(x<=sz[ls])k=ls;
			else if(x==sz[ls]+1){
				res=W[k];
				break;
			}
			else x-=sz[ls]+1,k=rs;
		}
		spaly(k,0);
		return res;
	}
	void insert(int x,int id,int v){
		int pr=kth(x),nx=kth(x+1);
		spaly(pr,0);
		pshtg(id,v,0);
		sz[id]=1;
		if(nx){
			spaly(nx,pr);
			pshdn(pr);
			pshdn(nx);
			sn[0][nx]=id;
			fa[id]=nx;
			pshup(nx);
			pshup(pr);
		}else{
			pshdn(pr);
			sn[1][pr]=id;
			fa[id]=pr;
			pshup(pr);
		}
	}
	void add(int x,int a,int d){
		if(x==1)pshtg(rt,d,d);
		else{
			int pr=kth(x-1);
			spaly(pr,0);
			pshdn(pr);
			if(sn[1][pr])
				pshtg(sn[1][pr],a,d);
		}
	}
	void pshdnall(int k){
		if(!k)return ;

		pshdn(k);
		pshdnall(ls);
//cout<<W[k]<<' ';
		pshdnall(rs);
	} 
}T;

int n,a[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++){
		int np=T.getpos(T.rt,a[i],0);
		T.insert(np,i+1,T.getv(np));
		T.add(np+1,a[i]*np,a[i]);
//T.pshdnall(T.rt); cout<<endl;
	}
	
	T.pshdnall(T.rt);
	
	int res=0;
	for(int i=1;i<=n+2;i++)	
		res=max(res,T.W[i]);
	cout<<res<<endl;
}

main(){
//	freopen("opt.in","r",stdin);
//	freopen("opt.out","w",stdout);
	ios::sync_with_stdio(0);
	solve();
}
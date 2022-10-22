#include<bits/stdc++.h>
using namespace std;
const int o=1.2e6+10;
int n,q,cnt,g[o/2][16];long long f[o][16],s[16];unsigned long long w[o],W[o],sw;map<int,int> mp;mt19937 rnd(time(0));
void modify(int id,int pos,int val,int l=1,int r=n){
	if(l==r){
		int t;
		if(mp.find(val)==mp.end()){
			t=mp[val]=++cnt;
			W[t]=((((unsigned long long)rnd())<<32)|rnd());
			for(int i=0;i<16;++i) g[t][i]=rnd();
		}
		else t=mp[val];
		for(int i=0;i<16;++i) f[id][i]=g[t][i];
		w[id]=W[t];
		return;
	}
	int md=l+r>>1;
	if(pos<=md) modify(id<<1,pos,val,l,md);
	else modify((id<<1)|1,pos,val,md+1,r);
	for(int i=0;i<16;++i) f[id][i]=f[id<<1][i]+f[(id<<1)|1][i];
	w[id]=(w[id<<1]^w[(id<<1)|1]);
}
void query1(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr){for(int i=0;i<16;++i) s[i]+=f[id][i];return;}
	int md=l+r>>1;
	if(ql<=md) query1(id<<1,ql,qr,l,md);
	if(md<qr) query1((id<<1)|1,ql,qr,md+1,r);
}
void query2(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr){sw^=w[id];return;}
	int md=l+r>>1;
	if(ql<=md) query2(id<<1,ql,qr,l,md);
	if(md<qr) query2((id<<1)|1,ql,qr,md+1,r);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,a;i<=n;++i) scanf("%d",&a),modify(1,i,a);
	for(int opt,l,r,k;q--;){
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1) modify(1,l,r);
		else{
			scanf("%d",&k);
			if(k==1){printf("YES\n");continue;}
			if(k==2){
				sw=0;query2(1,l,r);
				printf(sw?"NO\n":"YES\n");
				continue;
			}
			for(int i=0;i<16;++i) s[i]=0;
			query1(1,l,r);
			for(int i=0;i<=16;++i) if(i==16) printf("YES\n");else if(s[i]%k){printf("NO\n");break;}
		}
	}
	return 0;
}
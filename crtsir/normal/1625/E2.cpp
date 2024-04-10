#include<bits/stdc++.h>
using namespace std;
struct BIT{
	vector<long long>dat;
	int sz;
	void build(int SZ){
		sz=SZ+5;
		dat.resize(sz); 
	}
	void add(int x,long long y){
		while(x<sz){
			dat[x]+=y;
			x+=(x&-x);
		}
	}
	long long query(int x){
		long long ret=0;
		while(x){
			ret+=dat[x];
			x-=(x&-x);
		}return ret;
	}
}all,x[300003];
string s;
int n,q,nw,sz[300003],fa[300003],idx[300003],ord[300003],cntt[300003];
int main(){
	cin>>n>>q>>s;
	s=' '+s;
	int nw=1,cnt=1;
	for(int i=1;i<=n;i++)
		if(s[i]=='('){
			cntt[nw]++;
			cnt++;
			idx[cnt]=cntt[nw];
			fa[cnt]=nw;
			ord[i]=cnt;
			nw=cnt;
		}else
			if(nw!=1){
				ord[i]=nw;
				nw=fa[nw];
			}
	all.build(cnt);
	for(int i=1;i<=cnt;i++){
		all.add(i,1ll*cntt[i]*(cntt[i]+1)/2);
		x[i].build(cntt[i]);
	}
	for(int i=cnt;i>0;i--)
		sz[fa[i]]=sz[fa[i]]+(++sz[i]);
	for(int i=1;i<=q;i++){
		int tp,l,r;
		scanf("%d%d%d",&tp,&l,&r);
		if(tp==1){
			int nw=ord[l];
			x[fa[nw]].add(idx[nw],1);
			all.add(fa[nw],-cntt[fa[nw]]--);
		}else{
			l=ord[l];r=ord[r];
			long long ans=all.query(r+sz[r]-1)-all.query(l-1);
			long long res=idx[r]-idx[l]+1-x[fa[l]].query(idx[r])+x[fa[l]].query(idx[l]-1);
			ans+=res*(res+1)/2;
			printf("%lld\n",ans);
		}
	}
}
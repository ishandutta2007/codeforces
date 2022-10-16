#include<bits/stdc++.h>
using namespace std;
int n,q,v[300003],tp=-1,x[300003],w[300003];
vector<int>g[300003];
vector<long long>val[300003];
long long calc(int i,int j){
	return 1ll*abs(x[i]-x[j])*(w[i]+w[j]);
}
void add(int l,int r){
	g[l].push_back(r);
	val[l].push_back(calc(l,r));
}
long long ans[300003];
vector<int>idx[300003],r[300003];
long long dat[300003];
long long query(int x){
	long long ret=4333333333333333333;
	while(x){
		ret=min(ret,dat[x]);
		x-=(x&-x);
	}return ret;
}
void change(int x,long long y){
	while(x<=n){
		dat[x]=min(dat[x],y);
		x+=(x&-x);
	}
}
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%d%d",x+i,w+i);
		while(tp>=0){
			add(v[tp],i);
			if(w[v[tp]]<w[i])break;
			tp--;
		}
		v[++tp]=i;
	}
	for(int i=0;i<300003;i++)dat[i]=4333333333333333333; 
	for(int i=0;i<q;i++){
		int L,R;
		scanf("%d%d",&L,&R);
		r[L].push_back(R);
		idx[L].push_back(i);
	}
	for(int i=n;i>0;i--){
		for(int j=0;j<g[i].size();j++)
			change(g[i][j],val[i][j]);
		for(int j=0;j<r[i].size();j++)
			ans[idx[i][j]]=query(r[i][j]);
	}
	for(int i=0;i<q;i++)
		printf("%lld\n",ans[i]);
}
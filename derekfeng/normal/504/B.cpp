#include<bits/stdc++.h>
using namespace std;
int n,nn=1;
int p[200004],bit[200004];
void add(int id,int x){
	for(;id<=n;id+=id&-id)bit[id]+=x;
}
int got(int id){
	int ret=0;
	for(;id;id-=id&-id)ret+=bit[id];
	return ret;
}
int bs(int w){
	int n_=nn,ret=0;
	while(n_){
		if(ret+n_<=n&&w>bit[ret+n_])ret+=n_,w-=bit[ret];
		n_>>=1;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	while(nn*2<=n)nn<<=1;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);x++;
		int rk=x-got(x)-1;
		p[n-i]+=rk;
		add(x,1);
	}
	memset(bit,0,sizeof(bit));
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);x++;
		int rk=x-got(x)-1;
		p[n-i]+=rk;
		add(x,1);
	}
	for(int i=1;i<n;i++){
		p[i+1]+=p[i]/(i+1);
		p[i]%=(i+1); 
	}
	memset(bit,0,sizeof(bit));
	for(int i=1;i<=n;i++)add(i,1);
	for(int i=n-1;i>=0;i--){
		int rk=p[i]+1;
		int pos=bs(rk)+1;
		printf("%d ",pos-1);
		add(pos,-1);
	}
}
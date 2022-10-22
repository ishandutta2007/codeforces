#include<bits/stdc++.h>
using namespace std;
const int D=18;
int n,m,s[2][1048600],sz[1048600],lz[1048600];
void built(int id,int d){
	if(d<0)return;
	s[0][id]=id<<1,s[1][id]=id<<1|1;
	built(id<<1,d-1),built(id<<1|1,d-1);
}
void ins(int id,int x,int d){
	if(d<0){
		sz[id]=1;
		return;
	}
	if((1<<d)&x)ins(s[1][id],x,d-1);
	else ins(s[0][id],x,d-1);
	sz[id]=sz[s[0][id]]+sz[s[1][id]];
}
int f(int id,int x,int d){
	if(d<0)return sz[id];
	if(lz[id]){
		if((1<<d)&lz[id])swap(s[0][id],s[1][id]);
		lz[s[0][id]]^=lz[id],lz[s[1][id]]^=lz[id],lz[id]=0;
	}
	if((1<<d)&x)return f(s[1][id],x,d-1)+sz[s[0][id]];
	return f(s[0][id],x,d-1);
}
int main(){
	scanf("%d%d",&n,&m);
	built(1,D);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		ins(1,x,D);
	}
	while(m--){
		int x;scanf("%d",&x);
		lz[1]^=x;
		int l=-1,r=(1<<(D+1));
		while(r>l+1){
			int mid=(l+r)>>1;
			if(mid+1-f(1,mid,D)>0)r=mid;
			else l=mid;
		}
		printf("%d\n",r);
	}
}
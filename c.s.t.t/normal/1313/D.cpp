#include<bits/stdc++.h>
using namespace std;
int n,m,r,lim,f[2][1<<8],id[8];
pair<int,int>op[200100];
void chmax(int &x,int y){x=max(x,y);}
int main(){
	scanf("%d%d%d",&n,&m,&r);
	for(int i=0;i<n;i++)scanf("%d%d",&op[i].first,&op[i+n].first),op[i+n].first++,op[i].second=i+n,op[i+n].second=i;
	sort(op,op+n*2);
	for(int i=0;i<2*n;i++){
		memset(f[!(i&1)],0,sizeof(f[!(i&1)]));
//		printf("%d:%d,%d\n",i,op[i].first,op[i].second);
//		for(int j=0;j<lim;j++)printf("%d ",id[j]);puts("");
		if(op[i].second>=n){
			op[i].second-=n;
			for(int j=0;j<(1<<lim);j++){
				int extra=0;
				if(i)extra=(op[i].first-op[i-1].first)*__builtin_parity(j);
				chmax(f[!(i&1)][j|(1<<lim)],f[i&1][j]+extra);
				chmax(f[!(i&1)][j],f[i&1][j]+extra);
			}
			id[lim++]=op[i].second;
		}else{
			int k=find(id,id+lim,op[i].second)-id;
			int sub=(1<<k)-1;
			for(int j=0;j<(1<<lim);j++){
				int extra=0;
				if(i)extra=(op[i].first-op[i-1].first)*__builtin_parity(j);
				chmax(f[!(i&1)][(j&sub)|((j>>1)&(~sub))],f[i&1][j]+extra);
			}
			lim--;
			memcpy(id+k,id+k+1,(lim-k)*(sizeof(*id)));
		}
	}
	printf("%d\n",f[0][0]);
	return 0;
}
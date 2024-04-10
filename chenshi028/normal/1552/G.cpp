#include<cstdio>
using namespace std;
int n,k,sz[99];long long E,v[99][99],S[99],pre[99];
bool dfs(int nw,long long s){
	if(nw==k){
		int c1=__builtin_popcountll(s),c0=n-c1;long long target=((E>>c0)<<c0),need=(target^s);
		return (need&S[k])==need;
	}
	for(int i=__builtin_popcountll(s&S[nw]),j=i;i<=j+sz[nw];++i) if(!dfs(nw+1,(s|S[nw])&v[nw][i])) return false;
	return true;
}
int main(){
	scanf("%d%d",&n,&k);E=(1ll<<n)-1;
	for(int i=1,q;i<=k;++i){
		scanf("%d",&q);v[i][q]=E;
		for(int j;q;) scanf("%d",&j),S[i]|=(1ll<<(j-1)),v[i][--q]=(E^S[i]);
		sz[i]=__builtin_popcountll((E^pre[i-1])&S[i]);pre[i]=(pre[i-1]|S[i]);
	}
	if(n==1){printf("ACCEPTED");return 0;}
	if(pre[k]^E){printf("REJECTED");return 0;}
	if(dfs(1,0)) printf("ACCEPTED");
	else printf("REJECTED");
	return 0;
}
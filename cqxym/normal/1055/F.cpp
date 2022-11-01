#include<stdio.h>
#define R register int
#define L long long
#define I inline
#define N 1000001
int tot,pos[N],match[N],sz[N],trans[N][2];
L a[N];
I int CreateNode(int p,int d){
	if(trans[p][d]!=0){
		return trans[p][d];
	}
	tot++;
	trans[p][d]=tot;
	return tot;
}
int main(){
	int n,x;
	scanf("%d",&n);
	L k,ans=0;
	scanf("%lld",&k);
    for(R i=2;i<=n;i++){
    	scanf("%d",&x);
    	L y;
    	scanf("%lld",&y);
    	a[i]=a[x]^y;
	}
    for(R i=61;i!=-1;i--){
    	for(R j=0;j<=tot;j++){
    		trans[j][0]=trans[j][1]=sz[j]=0;
		}
		L s=0;
		tot=0;
		for(R j=1;j<=n;j++){
			pos[j]=CreateNode(pos[j],a[j]>>i&1);
			sz[pos[j]]++;
		}
		for(R j=1;j<=n;j++){
			s+=sz[trans[match[j]][a[j]>>i&1]];
		}
		for(R j=1;j<=n;j++){
			match[j]=trans[match[j]][(a[j]>>i&1)^s<k];
		}
		if(s<k){
			k-=s;
			ans|=1ll<<i;
		}
    }
    printf("%lld",ans);
    return 0;
}
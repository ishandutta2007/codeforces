#include<cstdio>
#define max(a,b)((a)>(b)?(a):(b))
const int N=2e5+3,K=18;
int lg[N],n,q,a[N],r[N],b[N],fr[N][K],fb[N][K],ans;
inline int Maxr(int l,int r){int t=lg[r-l+1];return max(fr[l][t],fr[r-(1<<t)+1][t]);}
inline int Maxb(int l,int r){int t=lg[r-l+1];return max(fb[l][t],fb[r-(1<<t)+1][t]);}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++){
	  scanf("%d",a+i);
	  b[a[i]]++,r[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	  fr[i][0]=r[a[i]],fb[i][0]=b[a[i]];
	for(int k=1;k<K;k++)
	  for(int i=1;i+(1<<k)-1<=n;i++)
		fr[i][k]=max(fr[i][k-1],fr[i+(1<<k-1)][k-1]),
		fb[i][k]=max(fb[i][k-1],fb[i+(1<<k-1)][k-1]);
	ans=n;
	for(int i=1,j;i<=n;i=j+1){
	  for(j=i;Maxr(i,j)>j;j=Maxr(i,j));
	  ans-=Maxb(i,j);
	}printf("%d",ans);
	return 0;
}
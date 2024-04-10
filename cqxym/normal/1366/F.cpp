#include<stdio.h>
#define R register int
#define L long long
#define I inline
#define P 1000000007
L dis[3000][2001],maxdis[3000];
int Last[2001],End[4001],Next[4001],Len[4001],ct;
I void Link(int&x,int&y,int&z){
	ct++;
	End[ct]=y;
	Len[ct]=z;
	Next[ct]=Last[x];
	Last[x]=ct;
}
I void SPFA(int&n){
	for(R i=0;i!=3000;i++){
		for(R j=1;j<=n;j++){
			dis[i][j]=-1e18;
		}
		maxdis[i]=-1e18;
	}
	dis[0][1]=0;
	for(R i=0;i!=2999;i++){
		for(R j=1;j<=n;j++){
			if(dis[i][j]!=-1e18){
				for(R k=Last[j];k!=0;k=Next[k]){
					int v=End[k];
					if(dis[i+1][v]<dis[i][j]+Len[k]){
						dis[i+1][v]=dis[i][j]+Len[k];
					}
				}
			}
		}
	}
	for(R i=0;i!=3000;i++){
		for(R j=1;j<=n;j++){
			if(dis[i][j]>maxdis[i]){
				maxdis[i]=dis[i][j];
			}
		}
	}
}
struct Edge{
	int Slope;
	L Intercept;
	I L GetF(int x){
		return (L)x*Slope+Intercept; 
	}
}e[4001];
I void AddEdge(int x,int y){
	e[ct].Slope=Len[y];
	e[ct].Intercept=dis[2999][x]-2999ll*Len[y];
	ct++;
}
I int GetMax(int x){
	L maxF=-1e18;
	int maxid;
	for(R i=0;i!=ct;i++){
		L F=e[i].GetF(x);
		if(maxF<F){
			maxF=F;
			maxid=i;
		}
	}
	return maxid;
}
int main(){
	int n,m,q,x,y,z;
	scanf("%d%d%d",&n,&m,&q);
	for(R i=0;i!=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		Link(x,y,z);
		Link(y,x,z);
	}
	SPFA(n);
	int ans=ct=0;
	for(R i=0;i!=3000&&i<=q;i++){
		ans=(ans+maxdis[i])%P;
	}
	if(q>2999){
		for(R i=m<<1;i!=0;i--){
			AddEdge(End[i],i);
		}
		int lt=3000;
		while(lt<=q){
			int l=lt+1,r=q,mid,res=lt,maxid;
			maxid=GetMax(lt);
			while(l<=r){
				mid=l+r>>1;
				if(GetMax(mid)==maxid){
					res=mid;
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			ans=((e[maxid].GetF(lt)+e[maxid].GetF(res))%P*(res-lt+1)%P*500000004%P+ans)%P;
			lt=res+1;
		}
	}
	printf("%d",ans);
	return 0;
}
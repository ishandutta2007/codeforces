#include<stdio.h>
#define R register int
#define I inline void
const int N=600001,M=1200001;
int Last[N],sz[N],Next[M],End[M],Len[M],Start[M],f[N],ct;
inline int Min(int &x,int y){
	return x<y?x:y;
}
I Add(int &x,int &y,int &z){
	ct++;
	Start[ct]=x;
	End[ct]=y;
	Len[ct]=z;
	Next[ct]=Last[x];
	Last[x]=ct;
}
I Swap(int &x,int &y){
	int t=x;
	x=y;
	y=t;
}
I DFS(int x,int F){
	f[x]=F;
	sz[x]=1;
	for(R i=Last[x];i!=0;i=Next[i]){
		if(End[i]!=F){
			DFS(End[i],x);
			sz[x]+=sz[End[i]];
		}
	}
}
I Solve(){
	int k,x,y,z;
	scanf("%d",&k);
	k<<=1;
	for(R i=1;i!=k;i++){
		scanf("%d%d%d",&x,&y,&z);
		Add(x,y,z);
		Add(y,x,z);
	}
	DFS(1,0);
	long long ans1=0,ans2=0;
	for(R i=1;i<ct;i+=2){
		x=Start[i];
		y=End[i];
		z=Len[i];
		if(f[y]==x){
			Swap(x,y);
		}
		Last[i]=Last[i+1]=0;
		ans1+=(sz[x]&1)*Len[i];
		ans2+=(long long)Min(sz[x],k-sz[x])*Len[i];
	}
	ct=0;
	printf("%lld %lld\n",ans1,ans2);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
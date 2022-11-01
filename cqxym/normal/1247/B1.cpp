#include<stdio.h>
#define R register int
int ct[1000001],a[200001];
inline int Min(int &x,int y){
	return x<y?x:y;
}
inline void Solve(){
	int n,d,tot=0,ans;
	scanf("%d%d%d",&n,&d,&d);
	for(R i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(R i=0;i<d;i++){
		if(ct[a[i]]==0){
			tot++;
		}
		ct[a[i]]++;
	}
	ans=tot;
	for(R i=d;i<n;i++){
		if(ct[a[i-d]]==1){
			tot--;
		}
		ct[a[i-d]]--;
		if(ct[a[i]]==0){
			tot++;
		}
		ct[a[i]]++;
		ans=Min(ans,tot);
	}
	printf("%d\n",ans);
	for(R i=0;i<n;i++){
		ct[a[i]]=0;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}
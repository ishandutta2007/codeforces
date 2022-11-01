#include<stdio.h>
#define R register int
char s[200003],c[200000];
int g[200001],n,k;
int Min(int x,int y){
	return x<y?x:y;
}
void Compare(int x){
	for(R i=0;i<n;i++){
		g[i+1]=g[i];
		if(c[i]!=s[i+x]){
			g[i+1]++;
		}
	}
}
int Get(){
	int ans=2e6;
	for(R i=k;i<=n;i++){
		ans=Min(ans,g[i]-g[i-k]);
	}
	return ans;
}
void Solve(){
	int ans=2e6;
	scanf("%d%d\n",&n,&k);
	for(R i=0;i<n;i++){
		c[i]=getchar();
	}
	for(R i=0;i<3;i++){
		Compare(i);
		ans=Min(ans,Get());
		for(R j=0;j<=n;j++){
			g[j]=0;
		}
	}
	printf("%d\n",ans);
}
int main(){
	for(R i=0;i<200004;i++){
		if(i%3==0){
			s[i]='R';
		}else if(i%3==1){
			s[i]='G';
		}else{
			s[i]='B';
		}
	}
	int q;
	scanf("%d",&q);
	for(R i=0;i<q;i++){
		Solve();
	}
	return 0;
}
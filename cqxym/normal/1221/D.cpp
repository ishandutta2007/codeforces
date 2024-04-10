#include<stdio.h>
#define R register int
#define ll long long
ll f[300001][3];
int a[300001],b[300001];
ll Min(ll x,ll y){
	return x<y?x:y;
}
void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
	}
	f[0][1]=b[0];
	f[0][2]=b[0]<<1;
	for(R i=1;i<n;i++){
		if(a[i]==a[i-1]){
			f[i][0]=Min(f[i-1][1],f[i-1][2]);
			f[i][1]=Min(f[i-1][0],f[i-1][2])+b[i];
			f[i][2]=Min(f[i-1][0],f[i-1][1])+b[i]*2;
		}else if(a[i]==a[i-1]-1){
			f[i][0]=Min(Min(f[i-1][0],f[i-1][1]),f[i-1][2]);
			f[i][1]=Min(f[i-1][1],f[i-1][2])+b[i];
			f[i][2]=Min(f[i-1][0],f[i-1][2])+b[i]*2;
		}else if(a[i]==a[i-1]-2){
			f[i][0]=Min(Min(f[i-1][0],f[i-1][1]),f[i-1][2]);
			f[i][1]=Min(Min(f[i-1][0],f[i-1][1]),f[i-1][2])+b[i];
			f[i][2]=Min(f[i-1][1],f[i-1][2])+b[i]*2;
		}else if(a[i]==a[i-1]+1){
			f[i][0]=Min(f[i-1][0],f[i-1][2]);
			f[i][1]=Min(f[i-1][0],f[i-1][1])+b[i];
			f[i][2]=Min(Min(f[i-1][0],f[i-1][1]),f[i-1][2])+b[i]*2;
		}else if(a[i]==a[i-1]+2){
			f[i][0]=Min(f[i-1][0],f[i-1][1]);
			f[i][1]=Min(Min(f[i-1][0],f[i-1][1]),f[i-1][2])+b[i];
			f[i][2]=f[i][1]+b[i];
		}else{
			f[i][0]=f[i][1]=f[i][2]=Min(Min(f[i-1][0],f[i-1][1]),f[i-1][2]);
			f[i][1]+=b[i];
			f[i][2]+=b[i]<<1;
		}
	}
	printf("%lld\n",Min(f[n-1][0],Min(f[n-1][1],f[n-1][2])));
}
int main(){
	int q;
	scanf("%d",&q);
	for(R i=0;i<q;i++){
		Solve();
	}
	return 0;
}